#include <libnile.h>
struct nile_main : public nile_t {
 class global *parent;
 nile_main(global *parent_);
 nile_t *call();
 };

struct nile_while : public nile_t {
 class closure_43 *parent;
 nile_t *var_cond;
 nile_while(closure_43 *parent_);
 nile_t *call(nile_t *);
 };

struct nile_priv0 : public nile_t {
 class closure_3 *parent;
 nile_t *var_block;
 nile_priv0(closure_3 *parent_);
 nile_t *call(nile_t *);
 };

struct closure_0 : public nile_t {
 class closure_1 *parent;
 closure_0(closure_1 *parent_);
 nile_t *call();
};

struct closure_1 : public nile_t {
 class nile_priv0 *parent;
 closure_1(nile_priv0 *parent_);
 nile_t *call();
};

struct closure_3 : public nile_t {
 class nile_while *parent;
 nile_t *var_priv0;
 closure_3(nile_while *parent_);
 nile_t *call();
};

struct nile_for : public nile_t {
 class closure_43 *parent;
 nile_t *var_init;
 nile_for(closure_43 *parent_);
 nile_t *call(nile_t *);
 };

struct nile_priv1 : public nile_t {
 class closure_13 *parent;
 nile_t *var_cond;
 nile_priv1(closure_13 *parent_);
 nile_t *call(nile_t *);
 };

struct nile_priv2 : public nile_t {
 class closure_11 *parent;
 nile_t *var_step;
 nile_priv2(closure_11 *parent_);
 nile_t *call(nile_t *);
 };

struct nile_priv3 : public nile_t {
 class closure_9 *parent;
 nile_t *var_block;
 nile_priv3(closure_9 *parent_);
 nile_t *call(nile_t *);
 };

struct closure_5 : public nile_t {
 class closure_6 *parent;
 closure_5(closure_6 *parent_);
 nile_t *call();
};

struct closure_6 : public nile_t {
 class closure_7 *parent;
 closure_6(closure_7 *parent_);
 nile_t *call();
};

struct closure_7 : public nile_t {
 class nile_priv3 *parent;
 closure_7(nile_priv3 *parent_);
 nile_t *call();
};

struct closure_9 : public nile_t {
 class nile_priv2 *parent;
 nile_t *var_priv3;
 closure_9(nile_priv2 *parent_);
 nile_t *call();
};

struct closure_11 : public nile_t {
 class nile_priv1 *parent;
 nile_t *var_priv2;
 closure_11(nile_priv1 *parent_);
 nile_t *call();
};

struct closure_13 : public nile_t {
 class nile_for *parent;
 nile_t *var_priv1;
 closure_13(nile_for *parent_);
 nile_t *call();
};

struct nile_map : public nile_t {
 class closure_43 *parent;
 nile_t *var_x;
 nile_map(closure_43 *parent_);
 nile_t *call(nile_t *);
 };

struct nile_priv4 : public nile_t {
 class closure_18 *parent;
 nile_t *var_y;
 nile_priv4(closure_18 *parent_);
 nile_t *call(nile_t *);
 };

struct closure_15 : public nile_t {
 class closure_16 *parent;
 closure_15(closure_16 *parent_);
 nile_t *call();
};

struct closure_16 : public nile_t {
 class nile_priv4 *parent;
 nile_t *var_l;
 closure_16(nile_priv4 *parent_);
 nile_t *call();
};

struct closure_18 : public nile_t {
 class nile_map *parent;
 nile_t *var_f;
 nile_t *var_priv4;
 closure_18(nile_map *parent_);
 nile_t *call();
};

struct nile_foldl : public nile_t {
 class closure_43 *parent;
 nile_t *var_f;
 nile_foldl(closure_43 *parent_);
 nile_t *call(nile_t *);
 };

struct nile_priv5 : public nile_t {
 class closure_25 *parent;
 nile_t *var_v;
 nile_priv5(closure_25 *parent_);
 nile_t *call(nile_t *);
 };

struct nile_priv6 : public nile_t {
 class closure_23 *parent;
 nile_t *var_l;
 nile_priv6(closure_23 *parent_);
 nile_t *call(nile_t *);
 };

struct closure_20 : public nile_t {
 class closure_21 *parent;
 closure_20(closure_21 *parent_);
 nile_t *call();
};

struct closure_21 : public nile_t {
 class nile_priv6 *parent;
 closure_21(nile_priv6 *parent_);
 nile_t *call();
};

struct closure_23 : public nile_t {
 class nile_priv5 *parent;
 nile_t *var_priv6;
 closure_23(nile_priv5 *parent_);
 nile_t *call();
};

struct closure_25 : public nile_t {
 class nile_foldl *parent;
 nile_t *var_priv5;
 closure_25(nile_foldl *parent_);
 nile_t *call();
};

struct nile_foldr : public nile_t {
 class closure_43 *parent;
 nile_t *var_f;
 nile_foldr(closure_43 *parent_);
 nile_t *call(nile_t *);
 };

struct nile_priv7 : public nile_t {
 class closure_32 *parent;
 nile_t *var_v;
 nile_priv7(closure_32 *parent_);
 nile_t *call(nile_t *);
 };

struct nile_priv8 : public nile_t {
 class closure_30 *parent;
 nile_t *var_l;
 nile_priv8(closure_30 *parent_);
 nile_t *call(nile_t *);
 };

struct closure_27 : public nile_t {
 class closure_28 *parent;
 closure_27(closure_28 *parent_);
 nile_t *call();
};

struct closure_28 : public nile_t {
 class nile_priv8 *parent;
 closure_28(nile_priv8 *parent_);
 nile_t *call();
};

struct closure_30 : public nile_t {
 class nile_priv7 *parent;
 nile_t *var_priv8;
 closure_30(nile_priv7 *parent_);
 nile_t *call();
};

struct closure_32 : public nile_t {
 class nile_foldr *parent;
 nile_t *var_priv7;
 closure_32(nile_foldr *parent_);
 nile_t *call();
};

struct nile_filter : public nile_t {
 class closure_43 *parent;
 nile_t *var_f;
 nile_filter(closure_43 *parent_);
 nile_t *call(nile_t *);
 };

struct nile_priv9 : public nile_t {
 class closure_39 *parent;
 nile_t *var_l;
 nile_priv9(closure_39 *parent_);
 nile_t *call(nile_t *);
 };

struct closure_35 : public nile_t {
 class closure_36 *parent;
 closure_35(closure_36 *parent_);
 nile_t *call();
};

struct closure_34 : public nile_t {
 class closure_36 *parent;
 closure_34(closure_36 *parent_);
 nile_t *call();
};

struct closure_36 : public nile_t {
 class closure_37 *parent;
 closure_36(closure_37 *parent_);
 nile_t *call();
};

struct closure_37 : public nile_t {
 class nile_priv9 *parent;
 closure_37(nile_priv9 *parent_);
 nile_t *call();
};

struct closure_39 : public nile_t {
 class nile_filter *parent;
 nile_t *var_priv9;
 closure_39(nile_filter *parent_);
 nile_t *call();
};

struct nile_priv10 : public nile_t {
 class closure_43 *parent;
 nile_t *var_x;
 nile_priv10(closure_43 *parent_);
 nile_t *call(nile_t *);
 };

struct closure_41 : public nile_t {
 class nile_priv10 *parent;
 closure_41(nile_priv10 *parent_);
 nile_t *call();
};

struct closure_43 : public nile_t {
 class nile_main *parent;
 nile_t *var_filter;
 nile_t *var_foldl;
 nile_t *var_foldr;
 nile_t *var_for;
 nile_t *var_l;
 nile_t *var_map;
 nile_t *var_priv10;
 nile_t *var_while;
 closure_43(nile_main *parent_);
 nile_t *call();
};

closure_0::closure_0(class closure_1 *parent_) : parent(parent_) {}
nile_t *closure_0::call(void) {
  nile_t *ret;
  ret=parent->parent->parent->parent->parent->parent->parent->var_if->call(parent->parent->parent->parent->var_cond)->call(parent->parent->var_block)->call(parent->parent->parent->parent->parent->parent->parent->var_break);
  return ret;
}

closure_1::closure_1(class nile_priv0 *parent_) : parent(parent_) {}
nile_t *closure_1::call(void) {
  nile_t *ret;
  ret=parent->parent->parent->parent->parent->parent->var_loop->call((new closure_0(this)));
  return ret;
}

nile_priv0::nile_priv0(closure_3 *parent_) : parent(parent_) {}

nile_t *nile_priv0::call(nile_t *block_) {
 var_block=block_;
 return (new closure_1(this))->call();
}
closure_3::closure_3(class nile_while *parent_) : parent(parent_) {}
nile_t *closure_3::call(void) {
  nile_t *ret;
  ret=var_priv0=(new nile_priv0(this));
  return ret;
}

nile_while::nile_while(closure_43 *parent_) : parent(parent_) {}

nile_t *nile_while::call(nile_t *cond_) {
 var_cond=cond_;
 return (new closure_3(this))->call();
}
closure_5::closure_5(class closure_6 *parent_) : parent(parent_) {}
nile_t *closure_5::call(void) {
  nile_t *ret;
  ret=parent->parent->parent->parent->parent->parent->parent->parent->parent->parent->parent->parent->var_apply->call(parent->parent->parent->var_block)->call(parent->parent->parent->var_block);
  ret=parent->parent->parent->parent->parent->parent->parent->parent->parent->parent->parent->parent->var_apply->call(parent->parent->parent->parent->parent->var_step)->call(parent->parent->parent->parent->parent->var_step);
  return ret;
}

closure_6::closure_6(class closure_7 *parent_) : parent(parent_) {}
nile_t *closure_6::call(void) {
  nile_t *ret;
  ret=parent->parent->parent->parent->parent->parent->parent->parent->parent->parent->parent->var_if->call(parent->parent->parent->parent->parent->parent->var_cond)->call((new closure_5(this)))->call(parent->parent->parent->parent->parent->parent->parent->parent->parent->parent->parent->var_break);
  return ret;
}

closure_7::closure_7(class nile_priv3 *parent_) : parent(parent_) {}
nile_t *closure_7::call(void) {
  nile_t *ret;
  ret=parent->parent->parent->parent->parent->parent->parent->parent->parent->parent->var_loop->call((new closure_6(this)));
  return ret;
}

nile_priv3::nile_priv3(closure_9 *parent_) : parent(parent_) {}

nile_t *nile_priv3::call(nile_t *block_) {
 var_block=block_;
 return (new closure_7(this))->call();
}
closure_9::closure_9(class nile_priv2 *parent_) : parent(parent_) {}
nile_t *closure_9::call(void) {
  nile_t *ret;
  ret=var_priv3=(new nile_priv3(this));
  return ret;
}

nile_priv2::nile_priv2(closure_11 *parent_) : parent(parent_) {}

nile_t *nile_priv2::call(nile_t *step_) {
 var_step=step_;
 return (new closure_9(this))->call();
}
closure_11::closure_11(class nile_priv1 *parent_) : parent(parent_) {}
nile_t *closure_11::call(void) {
  nile_t *ret;
  ret=var_priv2=(new nile_priv2(this));
  return ret;
}

nile_priv1::nile_priv1(closure_13 *parent_) : parent(parent_) {}

nile_t *nile_priv1::call(nile_t *cond_) {
 var_cond=cond_;
 return (new closure_11(this))->call();
}
closure_13::closure_13(class nile_for *parent_) : parent(parent_) {}
nile_t *closure_13::call(void) {
  nile_t *ret;
  ret=parent->var_init;
  ret=var_priv1=(new nile_priv1(this));
  return ret;
}

nile_for::nile_for(closure_43 *parent_) : parent(parent_) {}

nile_t *nile_for::call(nile_t *init_) {
 var_init=init_;
 return (new closure_13(this))->call();
}
closure_15::closure_15(class closure_16 *parent_) : parent(parent_) {}
nile_t *closure_15::call(void) {
  nile_t *ret;
  ret=parent->parent->parent->parent->parent->parent->parent->var_cons->call(parent->parent->parent->var_f->call(parent->parent->parent->parent->parent->parent->parent->var_head->call(parent->var_l)))->call(parent->parent->parent->parent->parent->var_map->call(parent->parent->parent->var_f)->call(parent->parent->parent->parent->parent->parent->parent->var_tail->call(parent->var_l)));
  return ret;
}

closure_16::closure_16(class nile_priv4 *parent_) : parent(parent_) {}
nile_t *closure_16::call(void) {
  nile_t *ret;
  ret=var_l=parent->var_y;
  ret=parent->parent->parent->parent->parent->parent->var_if->call(parent->parent->parent->parent->parent->parent->var_equal->call(var_l)->call(parent->parent->parent->parent->parent->parent->var_nil))->call(parent->parent->parent->parent->parent->parent->var_nil)->call((new closure_15(this)));
  return ret;
}

nile_priv4::nile_priv4(closure_18 *parent_) : parent(parent_) {}

nile_t *nile_priv4::call(nile_t *y_) {
 var_y=y_;
 return (new closure_16(this))->call();
}
closure_18::closure_18(class nile_map *parent_) : parent(parent_) {}
nile_t *closure_18::call(void) {
  nile_t *ret;
  ret=var_f=parent->var_x;
  ret=var_priv4=(new nile_priv4(this));
  return ret;
}

nile_map::nile_map(closure_43 *parent_) : parent(parent_) {}

nile_t *nile_map::call(nile_t *x_) {
 var_x=x_;
 return (new closure_18(this))->call();
}
closure_20::closure_20(class closure_21 *parent_) : parent(parent_) {}
nile_t *closure_20::call(void) {
  nile_t *ret;
  ret=parent->parent->parent->parent->parent->parent->var_f->call(parent->parent->parent->parent->parent->parent->parent->var_foldl->call(parent->parent->parent->parent->parent->parent->var_f)->call(parent->parent->parent->parent->var_v)->call(parent->parent->parent->parent->parent->parent->parent->parent->parent->var_tail->call(parent->parent->var_l)))->call(parent->parent->parent->parent->parent->parent->parent->parent->parent->var_head->call(parent->parent->var_l));
  return ret;
}

closure_21::closure_21(class nile_priv6 *parent_) : parent(parent_) {}
nile_t *closure_21::call(void) {
  nile_t *ret;
  ret=parent->parent->parent->parent->parent->parent->parent->parent->var_if->call(parent->parent->parent->parent->parent->parent->parent->parent->var_equal->call(parent->var_l)->call(parent->parent->parent->parent->parent->parent->parent->parent->var_nil))->call(parent->parent->parent->var_v)->call((new closure_20(this)));
  return ret;
}

nile_priv6::nile_priv6(closure_23 *parent_) : parent(parent_) {}

nile_t *nile_priv6::call(nile_t *l_) {
 var_l=l_;
 return (new closure_21(this))->call();
}
closure_23::closure_23(class nile_priv5 *parent_) : parent(parent_) {}
nile_t *closure_23::call(void) {
  nile_t *ret;
  ret=var_priv6=(new nile_priv6(this));
  return ret;
}

nile_priv5::nile_priv5(closure_25 *parent_) : parent(parent_) {}

nile_t *nile_priv5::call(nile_t *v_) {
 var_v=v_;
 return (new closure_23(this))->call();
}
closure_25::closure_25(class nile_foldl *parent_) : parent(parent_) {}
nile_t *closure_25::call(void) {
  nile_t *ret;
  ret=var_priv5=(new nile_priv5(this));
  return ret;
}

nile_foldl::nile_foldl(closure_43 *parent_) : parent(parent_) {}

nile_t *nile_foldl::call(nile_t *f_) {
 var_f=f_;
 return (new closure_25(this))->call();
}
closure_27::closure_27(class closure_28 *parent_) : parent(parent_) {}
nile_t *closure_27::call(void) {
  nile_t *ret;
  ret=parent->parent->parent->parent->parent->parent->var_f->call(parent->parent->parent->parent->parent->parent->parent->parent->parent->var_head->call(parent->parent->var_l))->call(parent->parent->parent->parent->parent->parent->parent->var_foldl->call(parent->parent->parent->parent->parent->parent->var_f)->call(parent->parent->parent->parent->var_v)->call(parent->parent->parent->parent->parent->parent->parent->parent->parent->var_tail->call(parent->parent->var_l)));
  return ret;
}

closure_28::closure_28(class nile_priv8 *parent_) : parent(parent_) {}
nile_t *closure_28::call(void) {
  nile_t *ret;
  ret=parent->parent->parent->parent->parent->parent->parent->parent->var_if->call(parent->parent->parent->parent->parent->parent->parent->parent->var_equal->call(parent->var_l)->call(parent->parent->parent->parent->parent->parent->parent->parent->var_nil))->call(parent->parent->parent->var_v)->call((new closure_27(this)));
  return ret;
}

nile_priv8::nile_priv8(closure_30 *parent_) : parent(parent_) {}

nile_t *nile_priv8::call(nile_t *l_) {
 var_l=l_;
 return (new closure_28(this))->call();
}
closure_30::closure_30(class nile_priv7 *parent_) : parent(parent_) {}
nile_t *closure_30::call(void) {
  nile_t *ret;
  ret=var_priv8=(new nile_priv8(this));
  return ret;
}

nile_priv7::nile_priv7(closure_32 *parent_) : parent(parent_) {}

nile_t *nile_priv7::call(nile_t *v_) {
 var_v=v_;
 return (new closure_30(this))->call();
}
closure_32::closure_32(class nile_foldr *parent_) : parent(parent_) {}
nile_t *closure_32::call(void) {
  nile_t *ret;
  ret=var_priv7=(new nile_priv7(this));
  return ret;
}

nile_foldr::nile_foldr(closure_43 *parent_) : parent(parent_) {}

nile_t *nile_foldr::call(nile_t *f_) {
 var_f=f_;
 return (new closure_32(this))->call();
}
closure_34::closure_34(class closure_36 *parent_) : parent(parent_) {}
nile_t *closure_34::call(void) {
  nile_t *ret;
  ret=parent->parent->parent->parent->parent->parent->parent->parent->var_cons->call(parent->parent->parent->parent->parent->parent->parent->parent->var_head->call(parent->parent->parent->var_l))->call(parent->parent->parent->parent->parent->parent->var_filter->call(parent->parent->parent->parent->parent->var_f)->call(parent->parent->parent->parent->parent->parent->parent->parent->var_tail->call(parent->parent->parent->var_l)));
  return ret;
}

closure_35::closure_35(class closure_36 *parent_) : parent(parent_) {}
nile_t *closure_35::call(void) {
  nile_t *ret;
  ret=parent->parent->parent->parent->parent->parent->var_filter->call(parent->parent->parent->parent->parent->var_f)->call(parent->parent->parent->parent->parent->parent->parent->parent->var_tail->call(parent->parent->parent->var_l));
  return ret;
}

closure_36::closure_36(class closure_37 *parent_) : parent(parent_) {}
nile_t *closure_36::call(void) {
  nile_t *ret;
  ret=parent->parent->parent->parent->parent->parent->parent->var_if->call(parent->parent->parent->parent->var_f->call(parent->parent->parent->parent->parent->parent->parent->var_head->call(parent->parent->var_l)))->call((new closure_34(this)))->call((new closure_35(this)));
  return ret;
}

closure_37::closure_37(class nile_priv9 *parent_) : parent(parent_) {}
nile_t *closure_37::call(void) {
  nile_t *ret;
  ret=parent->parent->parent->parent->parent->parent->var_if->call(parent->parent->parent->parent->parent->parent->var_equal->call(parent->var_l)->call(parent->parent->parent->parent->parent->parent->var_nil))->call(parent->parent->parent->parent->parent->parent->var_nil)->call((new closure_36(this)));
  return ret;
}

nile_priv9::nile_priv9(closure_39 *parent_) : parent(parent_) {}

nile_t *nile_priv9::call(nile_t *l_) {
 var_l=l_;
 return (new closure_37(this))->call();
}
closure_39::closure_39(class nile_filter *parent_) : parent(parent_) {}
nile_t *closure_39::call(void) {
  nile_t *ret;
  ret=var_priv9=(new nile_priv9(this));
  return ret;
}

nile_filter::nile_filter(closure_43 *parent_) : parent(parent_) {}

nile_t *nile_filter::call(nile_t *f_) {
 var_f=f_;
 return (new closure_39(this))->call();
}
closure_41::closure_41(class nile_priv10 *parent_) : parent(parent_) {}
nile_t *closure_41::call(void) {
  nile_t *ret;
  ret=parent->parent->parent->parent->var_print->call(parent->var_x)->call(new nilep_string(L"\n"));
  return ret;
}

nile_priv10::nile_priv10(closure_43 *parent_) : parent(parent_) {}

nile_t *nile_priv10::call(nile_t *x_) {
 var_x=x_;
 return (new closure_41(this))->call();
}
closure_43::closure_43(class nile_main *parent_) : parent(parent_) {}
nile_t *closure_43::call(void) {
  nile_t *ret;
  ret=var_while=(new nile_while(this));
  ret=var_for=(new nile_for(this));
  ret=var_map=(new nile_map(this));
  ret=var_foldl=(new nile_foldl(this));
  ret=var_foldr=(new nile_foldr(this));
  ret=var_filter=(new nile_filter(this));
  ret=var_l=parent->parent->var_cons->call(new nilep_number(1))->call(parent->parent->var_cons->call(new nilep_number(2))->call(parent->parent->var_cons->call(new nilep_number(3))->call(parent->parent->var_nil)));
  ret=var_map->call(var_priv10=(new nile_priv10(this)))->call(var_l);
  return ret;
}

nile_main::nile_main(global *parent_) : parent(parent_) {}

nile_t *nile_main::call() {
 return (new closure_43(this))->call();
}
int main(int argc, char *argv[]) { (new nile_main(new global()))->call(); }
