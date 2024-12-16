/*
当要同时操作2个对象时，就需要同时锁定这2个对象，而不是先锁定一个，
然后再锁定另一个。同时锁定多个对象的方法：std::lock(对象1.锁，对象2.锁...)
但是，有的时候，并不能同时得到所以要锁定的锁，必须是先锁定某个后，
再锁定其他的，这种情况就不能使用std::lock函数了，怎么办呢，使用有顺序的锁。
额外说明：lock_guard<模板类> ，中模板类的实现。这个模板类只要实现mutex所需要的三个成员函数即可：
lock(), unlock(), try_lock()。
*/

class hierarchical_mutex{
  std::mutex mtx;
  unsigned long const hcl_val;
  unsigned long pre_hcl_val;

  static thread_local unsigned long this_hcl_val;

  void check_for_hcl_violaction(){
    if(this_hcl_val <= hcl_val){
      throw std::logic_error("mutex hierarchy violated");
    }
  }
  void update_hierarchy_value(){
    pre_hcl_val = this_hcl_val;
    this_hcl_val = hcl_val;
  }

public:
  explicit hierarchical_mutex(unsigned long val):
    hcl_val(val), pre_hcl_val(0){}

  void lock(){
    check_for_hcl_violaction();
    mtx.lock();
    update_hierarchy_value();
  }

  void unlock(){
    this_hcl_val = pre_hcl_val;
    mtx.unlock();
  }

  bool try_lock(){
    check_for_hcl_violaction();
    if(!mtx.try_lock())
      return false;
    update_hierarchy_value();
    return true;
  }
};