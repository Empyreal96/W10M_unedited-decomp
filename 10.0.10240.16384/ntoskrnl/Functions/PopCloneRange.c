// PopCloneRange 
 
_DWORD *PopCloneRange(_DWORD *a1, char *a2, int a3, ...)
{
  _DWORD *result; // r0
  char *v7; // r6
  _DWORD *i; // r4
  unsigned int v9; // r2
  _DWORD *v10; // r2
  int varg_r3; // [sp+34h] [bp+14h] BYREF
  va_list varg_r3a; // [sp+34h] [bp+14h]
  va_list va1; // [sp+38h] [bp+18h] BYREF

  va_start(va1, a3);
  va_start(varg_r3a, a3);
  varg_r3 = va_arg(va1, _DWORD);
  if ( (PoDebug & 0x80) != 0 )
    DbgPrint("PopCloneRange - cloning page %p - %p, Tag %.4s\n", a2, &a2[a3], (const char *)varg_r3a);
  result = (_DWORD *)PopDiscardRange(a1, a2, a3, varg_r3);
  v7 = &a2[a3];
  for ( i = (_DWORD *)a1[10]; ; i = (_DWORD *)*i )
  {
    if ( i == a1 + 10 )
    {
LABEL_13:
      result = (_DWORD *)ExAllocatePoolWithTag(512, 24, 1885433160);
      if ( result )
      {
        result[2] = varg_r3;
        result[3] = a2;
        result[4] = v7;
        v10 = (_DWORD *)i[1];
        *result = i;
        result[1] = v10;
        if ( (_DWORD *)*v10 != i )
          __fastfail(3u);
        *v10 = result;
        i[1] = result;
        ++a1[12];
      }
      else if ( (int)a1[30] >= 0 )
      {
        a1[30] = -1073741670;
      }
      return result;
    }
    v9 = i[3];
    if ( (unsigned int)a2 >= v9 && (unsigned int)a2 <= i[4] )
      break;
    if ( (unsigned int)v7 >= v9 && (unsigned int)v7 <= i[4] )
      break;
    if ( (unsigned int)a2 <= v9 )
    {
      if ( (unsigned int)v7 >= i[4] )
        break;
      if ( v9 >= (unsigned int)a2 )
        goto LABEL_13;
    }
  }
  if ( (PoDebug & 0x80) != 0 )
    result = (_DWORD *)DbgPrint(
                         "PopCloneRange - coalescing range %p - %p (%.4s) with range %p - %p\n",
                         a2,
                         v7,
                         (const char *)varg_r3a,
                         (const void *)i[3],
                         (const void *)i[4]);
  if ( (unsigned int)a2 < i[3] )
    i[3] = a2;
  if ( (unsigned int)v7 > i[4] )
    i[4] = v7;
  return result;
}
