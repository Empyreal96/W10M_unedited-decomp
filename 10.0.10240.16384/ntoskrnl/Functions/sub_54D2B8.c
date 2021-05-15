// sub_54D2B8 
 
void __fastcall sub_54D2B8(int a1, int a2, unsigned int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17)
{
  int v17; // r5
  _DWORD *v18; // r6
  int v19; // r1
  int v20; // r3
  int v21; // r0
  int v22; // r3

  if ( (unsigned int)(a4 - 4) > 2 )
    JUMPOUT(0x4D7618);
  v19 = *(_DWORD *)(v17 + 16);
  if ( a3 > 0xE0 )
  {
    if ( a3 > 0x1000 )
    {
      v21 = SepAdtCopyToLsaSharedMemory(*v18, v19);
      if ( v21 < 0 )
      {
        SepAuditFailed(v21);
        goto LABEL_14;
      }
      a16 = 3;
      v20 = a5;
    }
    else
    {
      memmove(v18[9], v19, a3);
      v20 = v18[8];
      a16 = 2;
    }
    a17 = v20;
    a9 = 2359308;
  }
  else
  {
    memmove((int)&a17, v19, a3);
    a16 = 1;
  }
  v22 = *(_DWORD *)(v17 + 8);
  if ( v22 == 4 || v22 == 5 )
    ExFreePoolWithTag(*(_DWORD *)(v17 + 16), 0);
LABEL_14:
  JUMPOUT(0x4D75CA);
}
