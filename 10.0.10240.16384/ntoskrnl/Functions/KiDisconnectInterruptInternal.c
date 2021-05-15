// KiDisconnectInterruptInternal 
 
void __fastcall KiDisconnectInterruptInternal(int a1, int a2)
{
  int v4; // r4
  unsigned int v5; // r6
  unsigned int v6; // r4
  int v7; // r3
  int *v8; // r4
  int v9; // r1
  __int64 v10; // r0

  if ( *(_BYTE *)(a1 + 51) )
  {
    v4 = *(_DWORD *)(a1 + 44);
    v5 = (unsigned int)KeGetPcr() & 0xFFFFF000;
    if ( (v4 & 0xF0) != 0 )
    {
      v6 = v4 - 2048;
      if ( v6 < 0x400 )
      {
        v7 = *(_DWORD *)(v5 + 1324);
        if ( v7 )
        {
          v8 = (int *)(v7 + 4 * v6);
          if ( v8 )
          {
            v9 = *v8;
            if ( *(_DWORD *)(*v8 + 4) == *v8 + 4 )
            {
              HalDisableInterrupt(a2);
              *v8 = 0;
            }
            else
            {
              if ( a1 == v9 )
                *v8 = *(_DWORD *)(v9 + 4) - 4;
              v10 = *(_QWORD *)(a1 + 4);
              if ( *(_DWORD *)(v10 + 4) != a1 + 4 || *(_DWORD *)HIDWORD(v10) != a1 + 4 )
                __fastfail(3u);
              *(_DWORD *)HIDWORD(v10) = v10;
              *(_DWORD *)(v10 + 4) = HIDWORD(v10);
            }
          }
        }
      }
      *(_BYTE *)(a1 + 51) = 0;
    }
    else
    {
      sub_50F9EC();
    }
  }
}
