[![image](https://github.com/wow2658/CodingTest/assets/34699039/427e2aa7-9682-4058-8cbd-9fb1651da77d)](https://www.acmicpc.net/problem/1629)


# 분배 법칙

```
(A * B) % p = ((A % p) * (B % p)) % p
(A + B) % p = ((A % p) + (B % p)) % p
(A - B) % p = ((A % p) - (B % p) + p) % p
(A / B) % p = (A * B^(p - 2)) % p = (A % p) * (B^(p - 2) % p ) % p
```
참고링크: [모듈러연산증명](https://velog.io/@sw801733/%EB%82%98%EB%A8%B8%EC%A7%80-%EC%97%B0%EC%82%B0-%EB%B6%84%EB%B0%B0%EB%B2%95%EC%B9%99-%EB%AA%A8%EB%93%88%EB%9F%AC-%EC%97%B0%EC%82%B0), [페르마 소정리](https://davincicoding.tistory.com/12)

추천문제: [4375번(1)](https://www.acmicpc.net/problem/4375)
