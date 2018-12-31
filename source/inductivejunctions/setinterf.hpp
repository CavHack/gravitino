#include "JosephsonJunctions.hpp"
#include <rings/LaplacianOperators.hpp>

#include <memory>

#ifndef __SETINTERF_H__
#define __SETINTERF_H__

namespace Ring{


  class setinterf {
  public:
    /**
     * @brief Returns '1' (boolean true) if it exists a predicate which satisfies the condition.
     * @param make a prediction on the predicate
     * @return True iff an element that satisfies the predicate exists in the set
     */
    virtual bool exist(const std::unique_ptr<const JosephsonJunctionPredicate>& pred) const = 0;

    /*
     * Return size of the finite set in question
     *
     */

    virtual size_t size() const  = 0;

    /*
     *Returns whether a field element is a member of the set
     *
     */

    virtual bool contains(const JosephsonJunction& e) const = 0;

    virtual ~setinterf(){};


  };



} //namespace ring

#endif // __SETINTERF_H__
