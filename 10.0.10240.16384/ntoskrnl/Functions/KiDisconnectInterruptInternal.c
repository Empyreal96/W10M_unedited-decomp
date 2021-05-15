// KiDisconnectInterruptInternal 
 
int __fastcall KiDisconnectInterruptInternal(int a1, int a2)
{
  int v3; // r3
  int result; // r0
  int v6; // r4
  unsigned int v7; // r6
  unsigned int v8; // r4
  int v9; // r3
  int *v10; // r4
  int v11; // r1
  __int64 v12; // r0

  v3 = *(unsigned __int8 *)(a1 + 51);
  result = -1073741585;
  if ( v3 )
  {
    v6 = *(_DWORD *)(a1 + 44);
    v7 = (unsigned int)KeGetPcr() & 0xFFFFF000;
    if ( (v6 & 0xF0) != 0 )
    {
      v8 = v6 - 2048;
      if ( v8 < 0x400 )
      {
        v9 = *(_DWORD *)(v7 + 1324);
        if ( v9 )
        {
          v10 = (int *)(v9 + 4 * v8);
          if ( v10 )
          {
            v11 = *v10;
            if ( *(_DWORD *)(*v10 + 4) == *v10 + 4 )
            {
              HalDisableInterrupt(a2);
              *v10 = 0;
              result = 0;
            }
            else
            {
              if ( a1 == v11 )
                *v10 = *(_DWORD *)(v11 + 4) - 4;
              v12 = *(_QWORD *)(a1 + 4);
              if ( *(_DWORD *)(v12 + 4) != a1 + 4 || *(_DWORD *)HIDWORD(v12) != a1 + 4 )
                __fastfail(3u);
              *(_DWORD *)HIDWORD(v12) = v12;
              *(_DWORD *)(v12 + 4) = HIDWORD(v12);
              result = 296;
            }
          }
        }
      }
      *(_BYTE *)(a1 + 51) = 0;
    }
    else
    {
      result = sub_50F9EC(-1073741585);
    }
  }
  return result;
}
