// sub_4F4434 
 
_BYTE *__fastcall sub_4F4434(int a1, unsigned int a2, int a3, int a4)
{
  _BYTE *v4; // r4
  int v5; // r5
  _BYTE *v6; // r0
  int v8[4]; // [sp+0h] [bp-10h] BYREF

  v8[0] = a3;
  v8[1] = a4;
  v4 = 0;
  if ( RtlULongLongToULong(2 * a2, (unsigned __int64)a2 >> 31, v8) >= 0 )
  {
    v5 = v8[0];
    if ( v8[0] )
    {
      v6 = (_BYTE *)ExAllocatePoolWithTag(1, v8[0]);
      v4 = v6;
      if ( v6 )
        memset(v6, 0, v5);
    }
    else
    {
      v4 = 0;
    }
  }
  return v4;
}
