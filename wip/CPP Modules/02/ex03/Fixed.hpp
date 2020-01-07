/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 16:56:11 by ecaceres          #+#    #+#             */
/*   Updated: 2020/01/04 16:56:11 by ecaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		static const int _BIT_COUNT;

		int _value;

	public:
		Fixed(void);
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed &other);

		~Fixed(void);

		Fixed &operator =(const Fixed &other);

		bool operator >(const Fixed &right) const;
		bool operator <(const Fixed &right) const;
		bool operator >=(const Fixed &right) const;
		bool operator <=(const Fixed &right) const;
		bool operator ==(const Fixed &right) const;
		bool operator !=(const Fixed &right) const;

		Fixed operator +(const Fixed &right) const;
		Fixed operator -(const Fixed &right) const;
		Fixed operator *(const Fixed &right) const;
		Fixed operator /(const Fixed &right) const;

		Fixed &operator ++(void);
		Fixed &operator --(void);

		Fixed operator ++(int);
		Fixed operator --(int);

		int getRawBits(void) const;
		void setRawBits(int const raw);

		int toInt(void) const;
		float toFloat(void) const;

		bool isZero(void) const;

		static Fixed &min(Fixed &a, Fixed &b);
		const static Fixed &min(const Fixed &a, const Fixed &b);

		static Fixed &max(Fixed &a, Fixed &b);
		const static Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream &operator <<(std::ostream &stream, const Fixed &fixed);

#endif /* FIXED_HPP_ */
