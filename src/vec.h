#ifndef _VEC_H
#define _VEC_H

#include <ostream>
#include <cmath>

/**
 * @brief 3D Vector class
 *
 * This class is a 3D vector of type T that supports addition, subtraction,
 * dot product, and magnitude
 *
 * @tparam T Type of vector components
 */
template<typename T>

class _vec3{ ///< Generic 3D vector of type T

public:

    /**
     * @brief Default initialize vector to (0,0,0)
     */

    _vec3<T>(): d{0,0,0} {}

    /**
     * @brief Parameterized constructor
     *
     * Initializes vector with components
     *
     * @param a Component 1
     * @param b Component 2
     * @param c Component 3
     */

    _vec3<T>(T a, T b, T c) : d{a,b,c} {}

    /**
     *
     * @brief Access a component of the vector
     *
     * @param i Index of component where i = 0, 1, 2 for (0, 1, 2)
     * @return T& reference to component at index i
     */

    T& operator[] (int i) {return d[i];}

    /**
     * @brief Access a component of the vector (with a const)
     *
     * @param i Index of component where i = 0, 1, 2 for (0, 1, 2)
     * @return T Component at index i
     */

    T operator[] (int i) const {return d[i];}

    /**
     * @brief Adds two vectors
     * \f[
     * \mathbf{c} = \mathbf{a} + \mathbf{b}
     * \f]
     *
     * @param a Vector 1
     * @param b Vector 2
     * @return Resulting vector after addition
     */
    friend _vec3<T> operator+(const _vec3<T>&a, const _vec3<T>&b) {
        return _vec3<T>(a[0]+b[0],a[1]+b[1],a[2]+b[2]);
    }

    /**
     * @brief Subtracts two vectors
     * \f[
     * \mathbf{c} = \mathbf{a} - \mathbf{b}
     * \f]
     *
     * @param a Vector 1
     * @param b Vector 2
     * @return Resulting vector after subtraction
     */

    friend _vec3<T> operator-(const _vec3<T>&a, const _vec3<T>&b) {
        return _vec3<T>(a[0]-b[0],a[1]-b[1],a[2]-b[2]);
    }

    /**
     * @brief Dot products two vectors
     * @param a Vector 1
     * @param b Vector 2
     * @return T Dot product of the vectors \f$ [\mathbf{a} \cdot \mathbf{b} = a_1b_1 + a_2b_2 + a_3b_3] \f$
     */

    friend T dot(const _vec3<T>&a, const _vec3<T>&b) {
        return a[0]*b[0]+a[1]*b[1]+a[2]*b[2];
    }

    /**
     * @brief Computes the magnitude of the vector
     *\f[
     * ||\mathbf{a}|| = \sqrt{a_1^2 + a_2^2 + a_3^2}
     * \f]
     *
     * @param a The vector
     * @return double The magnitude of the vector
     */

    friend double mag(const _vec3<T>&a) {return sqrt(dot(a,a));}

    /**
     * @brief Outputs the vector to an output stream
     *
     * @param out Output stream
     * @param a The vector
     * @return std::ostream& Reference to output stream
     */
    friend std::ostream& operator<<(std::ostream &out, const _vec3<T>&a) {
        out<<a[0]<<" "<<a[1]<<" "<<a[2]; return out;
    }

protected:
    T d[3]; ///< Array storing components of the vector
};

using double3 = _vec3<double>; ///< Assign a nickname

#endif