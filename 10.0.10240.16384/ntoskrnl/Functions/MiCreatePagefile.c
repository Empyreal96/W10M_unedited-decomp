// MiCreatePagefile 
 
int __fastcall MiCreatePagefile(int a1, int a2, int a3, int a4, int a5, _DWORD *a6, int a7, char a8)
{
  BOOL v11; // r6
  _BYTE *v12; // r4
  int v13; // r3
  __int16 v14; // r3
  unsigned int v15; // r5
  unsigned int v16; // r8
  int v17; // r0
  int v18; // r5
  _BYTE *v20; // r9
  _BYTE *v21; // r0
  _BYTE *v22; // r7
  int v23; // r0
  _BYTE v24[176]; // [sp+0h] [bp-B0h] BYREF

  v11 = a2 == 0;
  v12 = (_BYTE *)ExAllocatePoolWithTag(512, 144, 538996045);
  if ( !v12 )
    v12 = v24;
  memset(v12, 0, 144);
  *((_DWORD *)v12 + 8) = a2;
  *(_DWORD *)v12 = a4;
  *((_DWORD *)v12 + 1) = a5;
  *((_DWORD *)v12 + 2) = a4;
  *((_DWORD *)v12 + 3) = a4 - 2;
  *((_DWORD *)v12 + 6) = a4 - 2;
  *((_DWORD *)v12 + 7) = a4 - 2;
  *((_DWORD *)v12 + 28) = a3;
  *((_DWORD *)v12 + 19) = dword_681270;
  v13 = dword_681270;
  *((_DWORD *)v12 + 32) = MiSystemPartition;
  *((_DWORD *)v12 + 29) = 0;
  *((_DWORD *)v12 + 22) = 4 * v13;
  *((_DWORD *)v12 + 12) = 0;
  *((_DWORD *)v12 + 13) = 0;
  *((_DWORD *)v12 + 31) = 0;
  if ( a7 >= 0 )
  {
    if ( v11 )
    {
      v14 = *((_WORD *)v12 + 48) | 0x60;
    }
    else
    {
      if ( (a7 & 0x40000000) != 0 )
        *((_WORD *)v12 + 48) |= 0x20u;
      if ( (a7 & 0x20000000) == 0 )
      {
LABEL_7:
        if ( (a8 & 1) != 0 )
          *((_WORD *)v12 + 48) |= 0x200u;
        if ( (a7 & 0x3C000000) != 0 )
          *((_DWORD *)v12 + 23) = (a7 & 0x3C000000u) >> 26;
        if ( v12 == v24 )
          goto LABEL_39;
        v15 = 2;
        if ( (a7 & 0x80000000) != 0 )
        {
          v15 = 1;
          v16 = 0;
        }
        else
        {
          if ( v11 )
            v15 = 0;
          v16 = 0;
          if ( !v15 )
          {
LABEL_16:
            if ( a6 )
            {
              *((_DWORD *)v12 + 14) = *a6;
              *((_DWORD *)v12 + 15) = a6[1];
            }
            else
            {
              RtlInitUnicodeString((unsigned int)(v12 + 56), 0);
            }
            if ( !v11 )
            {
              v23 = MiReservePageHash(*((_DWORD *)v12 + 1));
              if ( !v23 )
                goto LABEL_39;
              *((_DWORD *)v12 + 27) = v23;
            }
            v17 = MiCreatePageFileSpaceBitmaps(*((_DWORD *)v12 + 1));
            v18 = v17;
            if ( v17 )
            {
              *((_DWORD *)v12 + 16) = v17;
              RtlSetAllBits((_DWORD *)(v17 + 4));
              RtlClearBits((_BYTE *)(v18 + 4), 2u, *(_DWORD *)v12 - 2);
              RtlSetAllBits((_DWORD *)(v18 + 12));
              if ( !v11 )
                RtlClearBits((_BYTE *)(v18 + 12), 2u, *(_DWORD *)v12 - 2);
              if ( (*((_WORD *)v12 + 48) & 0x10) != 0 )
                *((_DWORD *)v12 + 18) = 2;
              else
                *((_DWORD *)v12 + 18) = *(_DWORD *)v12 >> 1;
              *((_DWORD *)v12 + 17) = 2;
              return (int)v12;
            }
LABEL_39:
            MiDeletePagefile((unsigned int)v12);
            return 0;
          }
        }
        v20 = v12;
        while ( 1 )
        {
          v21 = (_BYTE *)MiAllocateModWriterEntry(MiSystemPartition, dword_681270, 0);
          v22 = v21;
          if ( !v21 )
            goto LABEL_39;
          memset(v21, 0, 160);
          *((_DWORD *)v22 + 21) = v12;
          *((_DWORD *)v22 + 30) = MiSystemPartition;
          ++v16;
          *((_DWORD *)v20 + 9) = v22;
          v20 += 4;
          if ( v16 >= v15 )
            goto LABEL_16;
        }
      }
      v14 = *((_WORD *)v12 + 48) | 0x80;
    }
    *((_WORD *)v12 + 48) = v14;
    goto LABEL_7;
  }
  return sub_7BF928();
}
