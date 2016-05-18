#ifndef HAS_MEMBER_H
#define HAS_MEMBER_H

#include <type_traits>


#define EXPAND(...) __VA_ARGS__

#define CONCAT(x, y) CONCAT_(x, y)
#define CONCAT_(x, y) EXPAND(x ## y)


#define VAR_HELPER(T, var) std::declval<T>().var

#define FUNC_HELPER(T, func) &T::func


#define HAS_VAR(...) EXPAND(HAS_MEMBER(VAR_HELPER, __VA_ARGS__, CONCAT(has_, __VA_ARGS__)))

#define HAS_FUNC(...) EXPAND(HAS_MEMBER(FUNC_HELPER, __VA_ARGS__, CONCAT(has_, __VA_ARGS__)))


#define HAS_MEMBER(HELPER, member, Name, ...) \
\
template <class> \
constexpr bool CONCAT(Name, Impl) (...) { return false; } \
\
template <class T> \
constexpr bool CONCAT(Name, Impl) (std::decay_t<decltype(EXPAND(HELPER(T, member)), void())>*) { return true; } \
\
template <class T> \
constexpr bool Name () { return CONCAT(Name, Impl) <std::decay_t<T>>(nullptr); }


#endif //HAS_MEMBER_H