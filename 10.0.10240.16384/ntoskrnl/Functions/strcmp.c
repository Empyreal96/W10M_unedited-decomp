// strcmp 
 
unsigned int __fastcall strcmp(int a1, unsigned int *a2)
{
  int v2; // r3
  unsigned int result; // r0
  unsigned int v4; // t1
  unsigned int v8; // r0
  unsigned int v9; // t1

  v2 = a1 - (_DWORD)a2;
  if ( ((unsigned __int8)a2 & 3) == 0 )
    goto LABEL_5;
  while ( 1 )
  {
    result = *((unsigned __int8 *)a2 + v2);
    v4 = *(unsigned __int8 *)a2;
    a2 = (unsigned int *)((char *)a2 + 1);
    _CF = result >= v4;
    if ( result != v4 )
      break;
    if ( !result )
      return result;
    if ( ((unsigned __int8)a2 & 3) == 0 )
    {
LABEL_5:
      _R12 = 16843009;
      while ( (((_WORD)a2 + (_WORD)v2) & 0x3FFu) <= 0x3FC )
      {
        _R2 = *(unsigned int *)((char *)a2 + v2);
        v9 = *a2++;
        v8 = v9;
        if ( v9 != _R2 )
        {
          _R0 = bswap32(v8);
          _R2 = bswap32(_R2);
          __asm
          {
            SSUB8.W         R1, R0, R2
            UQSUB8.W        R3, R12, R2
          }
          if ( __clz(_R1) > __clz(_R3) )
            return 0;
          _CF = _R2 >= _R0;
          return _CF - !_CF;
        }
        __asm { UQSUB8.W        R2, R12, R2 }
        if ( _R2 )
          return 0;
      }
    }
  }
  return _CF - !_CF;
}
