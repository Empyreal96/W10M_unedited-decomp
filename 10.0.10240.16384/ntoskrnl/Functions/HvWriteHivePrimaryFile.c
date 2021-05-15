// HvWriteHivePrimaryFile 
 
int __fastcall HvWriteHivePrimaryFile(int a1, int a2, char a3)
{
  int v4; // r8
  int *v6; // r4
  int v7; // r3
  int v8; // r6
  int v9; // r0
  int v10; // r4
  int v11[3]; // [sp+10h] [bp-40h] BYREF
  int v12; // [sp+1Ch] [bp-34h]
  int v13; // [sp+20h] [bp-30h]
  _DWORD v14[10]; // [sp+28h] [bp-28h] BYREF

  v12 = 0;
  v13 = 0;
  v4 = 0;
  if ( (a3 & 1) != 0 )
  {
    v4 = 1;
    v12 = 1;
  }
  if ( !a2 )
    JUMPOUT(0x805FF8);
  if ( !*(_DWORD *)(a1 + 1916) )
    return sub_805FF4();
  v7 = *(_DWORD *)(a1 + 112);
  v6 = *(int **)(a1 + 1924);
  v6[2] = v7;
  v6[1] = v7 + 1;
  v6[127] = HvpHeaderCheckSum(v6);
  if ( CmpFailPrimarySave == 1 )
    goto LABEL_22;
  v13 = 1;
  v11[0] = 0;
  v14[0] = 0;
  v14[1] = v6;
  v14[2] = 4096;
  if ( !(*(int (__fastcall **)(int, _DWORD, _DWORD *, int, int *, int))(a1 + 20))(a1, 0, v14, 1, v11, v4) )
    JUMPOUT(0x80600E);
  if ( CmpFailPrimarySave == 2 )
LABEL_22:
    JUMPOUT(0x8060FC);
  v8 = *(_DWORD *)(a1 + 1916);
  if ( CmpFailPrimarySave == 3 )
  {
LABEL_18:
    v10 = -1073741823;
    goto LABEL_15;
  }
  if ( (*(int (__fastcall **)(int, _DWORD, int, _DWORD, int *, int))(a1 + 20))(
         a1,
         0,
         v8,
         *(_DWORD *)(a1 + 1920),
         v11,
         v4) )
  {
    if ( CmpFailPrimarySave != 4 && CmpFileFlushAndPurge(a1, 0) && CmpFailPrimarySave != 5 )
    {
      v9 = RtlNumberOfSetBits((unsigned int *)(a1 + 1904));
      CmpTraceHiveFlushWrotePrimaryFile(v9, v9 << 9);
      v13 = 0;
      v10 = 0;
      goto LABEL_15;
    }
    goto LABEL_18;
  }
  v10 = -1073741491;
LABEL_15:
  if ( !v8 )
    goto LABEL_22;
  HvpFinishPrimaryWrite(a1, v10 >= 0, v13);
  return v10;
}
