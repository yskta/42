/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 18:50:37 by yokitaga          #+#    #+#             */
/*   Updated: 2024/01/08 00:26:31 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main() {
    // コンストラクタのテスト
    Fixed a(5.05f);
    Fixed const b(Fixed(5.05f) * Fixed(2));

    // << 演算子のオーバーロード
    std::cout << "a: " << a << std::endl;

    // 前置インクリメント
    std::cout << "++a: " << ++a << std::endl;
    std::cout << "a: " << a << std::endl;

    // 後置インクリメント
    std::cout << "a++: " << a++ << std::endl;
    std::cout << "a: " << a << std::endl;

    std::cout << "b: " << b << std::endl;

    // 比較演算子のテスト
    std::cout << "a > b: " << (a > b) << std::endl;
    std::cout << "a < b: " << (a < b) << std::endl;
    std::cout << "a >= b: " << (a >= b) << std::endl;
    std::cout << "a <= b: " << (a <= b) << std::endl;
    std::cout << "a == b: " << (a == b) << std::endl;
    std::cout << "a != b: " << (a != b) << std::endl;

    // 四則演算のテスト
    std::cout << "a + b: " << (a + b) << std::endl;
    std::cout << "a - b: " << (a - b) << std::endl;
    std::cout << "a * b: " << (a * b) << std::endl;
    std::cout << "a / b: " << (a / b) << std::endl;

	Fixed c(5.05f);
    Fixed d(10.10f);
	const Fixed e(5.05f);
	const Fixed f(10.10f);

    // min 関数のテスト
	Fixed &min = Fixed::min(c, d);
    std::cout << "minRef: " << min << std::endl;

    // const 参照を受け取る min 関数のテスト
    const Fixed &minConstRef = Fixed::min(e, f);
    std::cout << "minConstRef: " << minConstRef << std::endl;

    // max 関数のテスト
	Fixed &max = Fixed::max(c, d);
    std::cout << "maxRef: " << max << std::endl;

    // const 参照を受け取る max 関数のテスト
    const Fixed &maxConstRef = Fixed::max(e, f);
    std::cout << "maxConstRef: " << maxConstRef << std::endl;
	
    return 0;
}