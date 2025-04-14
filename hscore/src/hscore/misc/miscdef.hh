#ifndef HSCORE_MISC_MISCDEF_HH
#define HSCORE_MISC_MISCDEF_HH

#define HS_CONCAT_IMPL(l, r) l##r
#define HS_STRINGIFY_IMPL(x) #x

#define HS_CONCAT(l, r) HS_CONCAT_IMPL(l, r)
#define HS_STRINGIFY(x) HS_STRINGIFY_IMPL(x)

#define HS_BIT(x) (1 << x)

#define HS_BIND_METHOD_ON_OBJECT(pobj, fn) \
	[this](auto&&... args) -> decltype(auto) { return pobj->fn(std::forward<decltype(args)>(args)...); }
#define HS_BIND_METHOD(fn) HS_BIND_METHOD_ON_OBJECT(this, fn)

#endif // HSCORE_MISC_MISCDEF_HH
