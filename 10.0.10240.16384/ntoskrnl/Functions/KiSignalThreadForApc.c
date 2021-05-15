// KiSignalThreadForApc 
 
int __fastcall KiSignalThreadForApc(int result, int a2, int a3)
{
  int v3; // r5
  int v4; // r3
  int v5; // r3
  _BYTE *v6; // r2
  int v7; // r3
  unsigned int *v8; // r6
  unsigned int v9; // r2
  __int64 v10; // kr00_8
  BOOL v11; // r1
  unsigned int *v12; // r2
  unsigned int v13; // r1
  int v14; // r0
  int v15; // r2
  unsigned int *v16; // r1
  unsigned int v17; // r4
  unsigned int v18; // r3
  char v19; // r2
  int v20; // r3
  unsigned int *v21; // r2
  unsigned int v22; // r1

  v3 = *(_DWORD *)(a2 + 8);
  if ( *(char *)(a2 + 44) != *(unsigned __int8 *)(v3 + 362) )
    return result;
  if ( v3 == *(_DWORD *)(result + 4) )
  {
    if ( *(_BYTE *)(a2 + 45) )
      return result;
    v11 = *(_DWORD *)(a2 + 28) != 0;
    if ( *(_DWORD *)(v3 + 308) )
    {
      if ( v11 || *(_WORD *)(v3 + 310) )
        return result;
    }
    *(_BYTE *)(v3 + 121) = 1;
    if ( !a3 )
    {
      *(_DWORD *)(v3 + 76) |= 0x40u;
      return result;
    }
    return HalRequestSoftwareInterrupt(1);
  }
  if ( !*(_BYTE *)(a2 + 45) )
  {
    __dmb(0xBu);
    *(_BYTE *)(v3 + 121) = 1;
    __dmb(0xFu);
    v4 = *(unsigned __int8 *)(v3 + 132);
    if ( v4 != 2 )
    {
      if ( v4 == 5
        && !*(_BYTE *)(v3 + 134)
        && !*(_WORD *)(v3 + 310)
        && (!*(_DWORD *)(a2 + 28) || !*(_WORD *)(v3 + 308) && !*(_BYTE *)(v3 + 120)) )
      {
        v5 = *(_BYTE *)(v3 + 72) & 7;
        if ( v5 == 1 || v5 == 4 )
        {
          v6 = *(_BYTE **)(v3 + 152);
          if ( v6 )
          {
            if ( (*v6 & 0x7F) == 21 )
            {
              v20 = *(unsigned __int8 *)(v3 + 332);
              *(_DWORD *)(v3 + 332) = v20;
              __dmb(0xBu);
              v21 = (unsigned int *)&v6[4 * v20 + 272];
              do
                v22 = __ldrex(v21);
              while ( __strex(v22 + 1, v21) );
            }
            else
            {
              __dmb(0xBu);
              v12 = (unsigned int *)(v6 + 24);
              do
                v13 = __ldrex(v12);
              while ( __strex(v13 + 1, v12) );
            }
            __dmb(0xBu);
          }
          v7 = *(_DWORD *)(v3 + 436);
          if ( v7 )
          {
            v8 = (unsigned int *)(v7 + 1928);
            while ( 1 )
            {
              do
                v9 = __ldrex(v8);
              while ( __strex(1u, v8) );
              __dmb(0xBu);
              if ( !v9 )
                break;
              do
              {
                __dmb(0xAu);
                __yield();
              }
              while ( *v8 );
            }
            if ( *(_DWORD *)(v3 + 436) )
            {
              v10 = *(_QWORD *)(v3 + 144);
              if ( *(_DWORD *)(v10 + 4) != v3 + 144 || *(_DWORD *)HIDWORD(v10) != v3 + 144 )
                sub_51DD64();
              *(_DWORD *)HIDWORD(v10) = v10;
              *(_DWORD *)(v10 + 4) = HIDWORD(v10);
              *(_DWORD *)(v3 + 436) = 0;
            }
            __dmb(0xBu);
            *v8 = 0;
          }
          *(_BYTE *)(v3 + 132) = 7;
          *(_DWORD *)(v3 + 144) = *(_DWORD *)(result + 1540);
          *(_DWORD *)(result + 1540) = v3 + 144;
          *(_DWORD *)(v3 + 136) = 256;
        }
        *(_BYTE *)(v3 + 72) |= 0x20u;
      }
      return result;
    }
    v14 = *(_DWORD *)(v3 + 328) & 0x7FFFFFFF;
    if ( *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594) != v14 )
    {
      v15 = (int)*(&KiProcessorBlock + *(_DWORD *)(v3 + 328));
      __dmb(0xBu);
      v16 = (unsigned int *)(v15 + 1676);
      do
        v17 = __ldrex(v16);
      while ( __strex(v17 | 1, v16) );
      __dmb(0xBu);
      v18 = (unsigned int)KeGetPcr();
      ++*(_DWORD *)((v18 & 0xFFFFF000) + 0x1414);
      return HalSendSoftwareInterrupt(v14, 1);
    }
    return HalRequestSoftwareInterrupt(1);
  }
  if ( *(_BYTE *)(v3 + 132) == 5 && *(_BYTE *)(v3 + 135) == 1 )
  {
    v19 = *(_BYTE *)(v3 + 72);
    if ( (v19 & 7) != 4 && (v19 & 7) != 3 && ((*(_DWORD *)(v3 + 76) & 0x10) != 0 || *(_BYTE *)(v3 + 122)) )
    {
      *(_BYTE *)(v3 + 72) = v19 | 0x40;
      result = KiSignalThread(result, v3, 192, 0);
      if ( result )
        *(_BYTE *)(v3 + 122) = 1;
    }
  }
  return result;
}
