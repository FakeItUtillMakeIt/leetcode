#pragma once


#ifndef TINY_URL_H
#define TINY_URL_H

#include <string>
#include <map>


using namespace std;



class Solution {
public:

	map<char, char> encodeMap;
	map<char, char> decodeMap;
	Solution() {
		for (int i=0;i<26;i++)
		{
			encodeMap[i + 'a'] = i + 'A';
			decodeMap[i + 'A'] = i + 'a';
		}
		string s = "http://www.google.com/search?hl=en&lr=&c2coff=1&rls=GGLG%2CGGLG%3A2005-26%2CGGLG%3Aen&q=http%3A%2F%2Fwww.google.com%2Fsearch%3Fhl%3Den%26lr%3D%26c2coff%3D1%26rls%3DGGLG%252CGGLG%253A2005-26%252CGGLG%253Aen%26q%3Dhttp%253A%252F%252Fwww.google.com%252Fsearch%253Fhl%253Den%2526lr%253D%2526c2coff%253D1%2526rls%253DGGLG%25252CGGLG%25253A2005-26%25252CGGLG%25253Aen%2526q%253Dhttp%25253A%25252F%25252Fwww.google.com%25252Fsearch%25253Fsourceid%25253Dnavclient%252526ie%25253DUTF-8%252526rls%25253DGGLG%25252CGGLG%25253A2005-26%25252CGGLG%25253Aen%252526q%25253Dhttp%2525253A%2525252F%2525252Fwww%2525252Egoogle%2525252Ecom%2525252Fsearch%2525253Fsourceid%2525253Dnavclient%25252526ie%2525253DUTF%2525252D8%25252526rls%2525253DGGLG%2525252CGGLG%2525253A2005%2525252D26%2525252CGGLG%2525253Aen%25252526q%2525253Dhttp%252525253A%252525252F%252525252Fuk2%252525252Emultimap%252525252Ecom%252525252Fmap%252525252Fbrowse%252525252Ecgi%252525253Fclient%252525253Dpublic%2525252526GridE%252525253D%252525252D0%252525252E12640%2525252526GridN%252525253D51%252525252E50860%2525252526lon%252525253D%252525252D0%252525252E12640%2525252526lat%252525253D51%252525252E50860%2525252526search%252525255Fresult%252525253DLondon%25252525252CGreater%252525252520London%2525252526db%252525253Dfreegaz%2525252526cidr%252525255Fclient%252525253Dnone%2525252526lang%252525253D%2525252526place%252525253DLondon%252525252CGreater%252525252BLondon%2525252526pc%252525253D%2525252526advanced%252525253D%2525252526client%252525253Dpublic%2525252526addr2%252525253D%2525252526quicksearch%252525253DLondon%2525252526addr3%252525253D%2525252526scale%252525253D100000%2525252526addr1%252525253D%2526btnG%253DSearch%26btnG%3DSearch&btnG=Search";
		auto ret = decode(encode(s));
	}

	// Encodes a URL to a shortened URL.
	string encode(string longUrl) {
		string ret = "";
		for (char c:longUrl)
		{
			for (auto tmp=encodeMap.begin();tmp!=encodeMap.end();tmp++)
			{
				if (tmp->first==c)
				{
					c = tmp->second;
				}
			}
			ret += c;
		}
		return ret;
	}

	// Decodes a shortened URL to its original URL.
	string decode(string shortUrl) {
		string ret = "";
		for (char c : shortUrl)
		{
			for (auto tmp = decodeMap.begin(); tmp != decodeMap.end(); tmp++)
			{
				if (tmp->first == c)
				{
					c = tmp->second;
				}
			}
			ret += c;
		}
		return ret;
	}
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));

#endif