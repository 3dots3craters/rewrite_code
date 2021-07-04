# rewrite_code

**기존 norm에 맞게 쓰여진 코드만을 대상으로 합니다**

<h3>사용법</h3>

1. norm-v3에 맞춰 바꾸고자 하는 파일과 같은 위치에 rewrite 실행파일을 위치시킵니다.
2. ./rewrite [파일명] 또는 ./rewrite *.c 

Error: SPACE_REPLACE_TAB    (line:  n, col:   n):	Found space when expecting tab
Error: TOO_MANY_TABS_FUNC   (line:  n, col:   n):	extra tabs before function name
위 두 가지 에러를 잡아줍니다.



만든 이유(쓰는중): 새로운 norm에 맞춰 코드를 하나하나 바꾸다 보니 이럴 시간에 '새 norm에 맞춰 코드 다시 써주는 프로그램'을 만드는 게 더 재밌겠다는 생각이 들었습니다.
앞서 jeonhyun님과 어떤 방식으로 위와 같은 프로그램을 만들면 좋을까에 대해 길게 얘기를 나누었던 터라 그 내용을 코드로 옮기는 것은 편했습니다.

하지만 하다보니 이차원 문자열을 만드는데 끝에 널을 안 넣어서 execve가 제대로 작동을 안 하거나..


samin님과 얘기를 나누며
라인 체크를 앞에서부터 하던 기존의 방식이 아니라 뒤에서부터 하면 되겠다는 생각이 들어서 코드 수정에 들어갔습니다.

samin님과 같이 보는데 변수명을 잘못 적었다는 사실을 알아차렸습니다.
len과 len2를 혼동하여 쓰고 있어 그런 사태가 벌어졌던 것입니다.
이를 계기로 len, len2 같은 변수명은 다시는 짓지 않아야겠다 다짐했습니다.
