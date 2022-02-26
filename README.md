<h4>[rewrite_code: norm-v3에 맞게 기존 코드를 개선합니다]</h4>
<h1>주의!!기존 norm-v2에 맞게 쓰여진 코드만을 대상으로 합니다!!(.c 파일만!!)</h1>



https://user-images.githubusercontent.com/66169740/155844899-2318f712-ad82-4ace-9693-e2c9f5ca315e.mov





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

- 새 파일 권한을 755에서 644로 바꿔 기존 파일의 권한과 동일하게 수정

<h3>21.07.06</h3>

- break ; 에서 break와 세미콜론 사이에 '\t'을 넣는 버그 수정

---------------
