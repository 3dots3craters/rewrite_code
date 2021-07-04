# rewrite_code

<h1>주의!!기존 norm에 맞게 쓰여진 코드만을 대상으로 합니다!!</h1>

<h3>사용법</h3>

 1. rewrite 실행파일의 위치는 어디든 상관없습니다!  
 2. <code>./rewrite [파일명]</code> 또는 <code>./rewrite *.c</code>  
 3. 그리고 <code>./rewrite ../../42cursus/circle_02/cub3D/check/*.c</code> 이런 식으로 써도 됩니다.
 
 (폴더명만 쓰는 건 안 됩니다! ex) <code>./rewrite ../gnl</code>(X))
<br>
<br>

> - Error: SPACE_REPLACE_TAB(line: n, col: n):Found space when expecting tab
> - Error: TOO_MANY_TABS_FUNC(line: n, col: n): extra tabs before function name
>
>  위 두 가지 에러가 나지 않게 코드를 개선해줍니다.



<br>

<br>


---------------

<h3>21.07.05</h3>
- 자료형 이름이 두 글자인 경우(ex. unsigned char 등) 자료형 이름 중간에 '\t'을 넣는 버그 수정




---------------
만든 이유와 과정(쓰는중...): 
새로운 norm에 맞춰 코드를 하나하나 바꾸다 보니 지루하기도 하고, 이럴 시간에 '새 norm에 맞춰 코드 다시 써주는 프로그램'을 만드는 게 더 재밌겠다는 생각이 들었습니다. 
앞서 jeonhyun님과 어떤 방식으로 위와 같은 프로그램을 만들면 좋을까에 대해 길게 얘기를 나누었던 터라 그 내용을 코드로 옮기는 것은 편했습니다.

하지만 하다보니 이차원 문자열을 만드는데 끝에 널을 안 넣어서 execve가 제대로 작동을 안 하거나...
execve의 연속된 사용을 위해 자식프로세스를 계속 생성해야 한다거나하는 변화를 계속 거쳤고

samin님과 얘기를 나누며 라인 체크를 앞에서부터 하던 기존의 방식이 아니라 뒤에서부터 하면 되겠다는 생각이 들어서 코드 수정에 들어갔습니다.
그러다 또 변수 선언 라인이 체크가 안되고 있길래 왜그런가 하고 봤더니 변수명을 잘못 적었다는 사실을 알아차렸습니다. 
len과 len2를 혼동하여 쓰고 있어 그런 사태가 벌어졌던 것입니다. 
이를 계기로 len, len2 같은 헷갈리는 변수명들은 다시는 짓지 않아야겠다 다짐했습니다.
