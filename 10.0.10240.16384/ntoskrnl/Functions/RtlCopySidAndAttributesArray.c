// RtlCopySidAndAttributesArray 
 
int __fastcall RtlCopySidAndAttributesArray(unsigned int a1, int *a2, unsigned int a3, int a4, int a5, int *a6, unsigned int *a7)
{
  unsigned int v8; // r6
  int *v10; // r8
  int v12; // r2
  unsigned int v13; // lr
  unsigned int v14; // r7
  int v15; // r1
  int v16; // t1
  unsigned int v17; // r2
  int result; // r0
  int v19; // [sp+0h] [bp-20h]

  v8 = 0;
  v10 = a2;
  if ( a1 )
  {
    v12 = a4 - (_DWORD)a2;
    v19 = a4 - (_DWORD)a2;
    while ( 1 )
    {
      v13 = 4 * (*(unsigned __int8 *)(*v10 + 1) + 2);
      v14 = (v13 + 3) & 0xFFFFFFFC;
      if ( v13 > a3 )
        break;
      *(int *)((char *)v10 + v12) = a5;
      a3 -= v14;
      *(int *)((char *)v10 + v12 + 4) = v10[1];
      v16 = *v10;
      v10 += 2;
      v15 = v16;
      v17 = 4 * (*(unsigned __int8 *)(v16 + 1) + 2);
      if ( v17 <= v13 )
        memmove(a5, v15, v17);
      ++v8;
      v12 = v19;
      a5 += v14;
      if ( v8 >= a1 )
        goto LABEL_7;
    }
    result = -1073741789;
  }
  else
  {
LABEL_7:
    result = 0;
    *a6 = a5;
    *a7 = a3;
  }
  return result;
}
