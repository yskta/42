/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 12:26:29 by yokitaga          #+#    #+#             */
/*   Updated: 2024/02/12 13:04:21 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
	// デフォルトコンストラクタで空の配列を作成
    Array<int> emptyArray;
    std::cout << "Empty array size: " << emptyArray.size() << std::endl;

    // サイズ 5 の配列を作成し、初期化
    Array<int> intArray(5);
    for (unsigned int i = 0; i < intArray.size(); ++i) {
        intArray[i] = i * 2;
    }

    // コピーコンストラクタと代入演算子の動作確認
    Array<int> copiedArray = intArray;
    Array<int> assignedArray;
    assignedArray = intArray;

    // 配列の内容を表示
    std::cout << "Original array elements: ";
    for (unsigned int i = 0; i < intArray.size(); ++i) {
        std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Copied array elements: ";
    for (unsigned int i = 0; i < copiedArray.size(); ++i) {
        std::cout << copiedArray[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Assigned array elements: ";
    for (unsigned int i = 0; i < assignedArray.size(); ++i) {
        std::cout << assignedArray[i] << " ";
    }
    std::cout << std::endl;

    // 配列の範囲外アクセスの例外処理
    //try {
    //    int value = intArray[10];
    //} catch (const Array<int>::OutOfBounds &ex) {
    //    std::cerr << "Exception: " << ex.what() << std::endl;
    //}
	return (0);
}