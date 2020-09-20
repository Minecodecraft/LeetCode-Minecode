//
//  main.swift
//  Test
//
//  Created by Jaylen Bian on 9/20/20.
//  Copyright © 2020 Jaylen Bian. All rights reserved.
//

import Foundation

class Solution {
    func reorderSpaces(_ text: String) -> String {
        let (space, words) = (text.reduce(0, { $0 + ($1 == " " ? 1 : 0) }), text.split(separator: " "))
        return words.count == 1 ? words[0] + String(repeating: " ", count: space) : words.joined(separator: String(repeating: " ", count: (space / (words.count - 1))) + String(repeating: " ", count: space % (words.count - 1)))
    }
}
