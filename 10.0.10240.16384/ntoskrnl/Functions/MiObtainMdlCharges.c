// MiObtainMdlCharges 
 
int __fastcall MiObtainMdlCharges(int a1, unsigned int a2, unsigned int a3, unsigned int a4, unsigned int a5, int a6, char a7)
{
  unsigned int v10; // r7
  int v11; // r2
  unsigned int v12; // r8
  int v13; // r10
  int v14; // r0
  int v15; // r6
  __int64 v16; // r1
  unsigned int v17; // r8
  unsigned int v18; // r4
  unsigned int v19; // r4

  if ( a5 > 0xFFFFF000 )
    return sub_511C58(32);
  v10 = (a5 + 4095) >> 12;
  if ( (a7 & 0x40) != 0
    && ((a7 & 0x20) == 0 || a2 > 0x400 || a3 < dword_640504 || (v10 & 0x3FF) != 0 || a4 != 1024 || a6 != 1)
    || (v11 = *(_DWORD *)(a1 + 3840) - 1024, v11 <= 0) )
  {
LABEL_48:
    JUMPOUT(0x511C7C);
  }
  if ( v10 > v11 )
  {
    if ( (a7 & 4) != 0 )
      goto LABEL_48;
    v10 = *(_DWORD *)(a1 + 3840) - 1024;
    if ( (a7 & 0x20) != 0 && a4 )
      v10 = v11 & ~(a4 - 1);
  }
  if ( !v10 )
    goto LABEL_48;
  v12 = v10 >> 4;
  if ( (a7 & 0x20) != 0 && a4 )
    v12 = a4;
  v13 = 4 * (v10 + 7);
  while ( 1 )
  {
    v14 = ExAllocatePoolWithTag(512, v13, 1768189261);
    v15 = v14;
    if ( v14 )
      break;
    if ( (a7 & 4) == 0 )
    {
      if ( v12 )
      {
        if ( v10 >= v12 )
        {
          v10 -= v12;
          v13 -= 4 * v12;
          if ( v10 )
            continue;
        }
      }
    }
    goto LABEL_48;
  }
  HIDWORD(v16) = v10 << 12;
  LODWORD(v16) = 0;
  *(_DWORD *)v14 = 0;
  *(_WORD *)(v14 + 6) = 0;
  *(_QWORD *)(v14 + 16) = v16;
  *(_DWORD *)(v14 + 24) = 0;
  *(_DWORD *)(v14 + 12) = 0;
  *(_WORD *)(v14 + 4) = 4 * ((((v10 << 12) + 4095) >> 12) + 7);
  if ( !MiChargeCommit(a1, v10, 1) )
  {
    ExFreePoolWithTag(v15, 0);
    goto LABEL_48;
  }
  v17 = v10;
  while ( !MiChargeResident(a1, v10, 1024) )
  {
    if ( (a7 & 4) == 0 )
    {
      if ( *(_DWORD *)(a1 + 3840) - 1024 > 0 )
      {
        if ( v10 > *(_DWORD *)(a1 + 3840) - 1024 )
          v10 = *(_DWORD *)(a1 + 3840) - 1024;
      }
      else
      {
        v10 = 0;
      }
      if ( (a7 & 0x20) != 0 && a4 )
        v10 &= ~(a4 - 1);
      if ( v10 )
        continue;
    }
    JUMPOUT(0x511C6C);
  }
  if ( v10 != v17 )
    MiReturnCommit(a1, v17 - v10);
  if ( (__int16 *)a1 == &MiSystemPartition )
  {
    do
      v18 = __ldrex(&dword_634A2C[27]);
    while ( __strex(v18 + v10, &dword_634A2C[27]) );
    do
      v19 = __ldrex((unsigned int *)&dword_634D94);
    while ( __strex(v19 + v10, (unsigned int *)&dword_634D94) );
  }
  *(_DWORD *)(v15 + 20) = v10 << 12;
  return v15;
}
