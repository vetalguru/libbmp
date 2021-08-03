#ifndef LIBBMP_INCLUDE_UNUSED_HPP_
#define LIBBMP_INCLUDE_UNUSED_HPP_

template <typename T> const T *UNUSED_VARIABLE(const T &unused) {
  return &unused;
}

#endif // LIBBMP_INCLUDE_UNUSED_HPP_
