#pragma once

#include <boost/type_index.hpp>
#include <iostream>
#include <vector>

namespace dp_tests {

template <typename T>
void byConstRef(const T& param)
{
   std::vector<T> vec{};
   using boost::typeindex::type_id_with_cvr;
   std::cout << "T = " << type_id_with_cvr<T>().pretty_name() << std::endl;
   std::cout << "param = " << type_id_with_cvr<decltype(param)>().pretty_name() << std::endl;
   vec.push_back(param);
}

template <typename T>
void byRef(T& param)
{
   std::vector<std::remove_cv_t<T>> vec{};
   using boost::typeindex::type_id_with_cvr;
   std::cout << "T = " << type_id_with_cvr<T>().pretty_name() << std::endl;
   std::cout << "param = " << type_id_with_cvr<decltype(param)>().pretty_name() << std::endl;
   vec.push_back(param);
}

template <typename T>
void byPointer(T* param)
{
   std::vector<std::remove_cv_t<T>> vec{};
   using boost::typeindex::type_id_with_cvr;
   std::cout << "T = " << type_id_with_cvr<T>().pretty_name() << std::endl;
   std::cout << "param = " << type_id_with_cvr<decltype(param)>().pretty_name() << std::endl;
   vec.push_back(*param);
}

template <typename T>
void byValue(T param)
{
   std::vector<T> vec{};
   using boost::typeindex::type_id_with_cvr;
   std::cout << "T = " << type_id_with_cvr<T>().pretty_name() << std::endl;
   std::cout << "param = " << type_id_with_cvr<decltype(param)>().pretty_name() << std::endl;
   vec.push_back(std::move(param));
}

template <typename T>
void byUniversalRef(T&& param)
{
   std::vector<std::remove_cv_t<std::remove_reference_t<T>>> vec{};
   using boost::typeindex::type_id_with_cvr;
   std::cout << "T = " << type_id_with_cvr<T>().pretty_name() << std::endl;
   std::cout << "param = " << type_id_with_cvr<decltype(param)>().pretty_name() << std::endl;
   vec.push_back(std::forward<T>(param));
}
}
