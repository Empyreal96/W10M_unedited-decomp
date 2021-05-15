// BgpDisplayCharacterGetContext 
 
int __fastcall BgpDisplayCharacterGetContext(int a1, int a2, int a3)
{
  _DWORD *v6; // r6
  _DWORD *v7; // r5
  int v9; // r2
  int v10; // r3
  int v11; // [sp+8h] [bp-38h] BYREF
  _DWORD v12[2]; // [sp+10h] [bp-30h] BYREF
  __int64 v13; // [sp+18h] [bp-28h] BYREF
  int v14; // [sp+20h] [bp-20h]

  v11 = 0;
  v6 = 0;
  v7 = (_DWORD *)BgpFwAllocateMemory(0x18u);
  if ( v7 )
  {
    v12[0] = 0;
    v12[1] = 0;
    v13 = *(_QWORD *)a2;
    v14 = v13;
    if ( BgpTxtCreateRegion(v12, &v13, a1, &v11, a3) < 0 )
      return sub_8DFAB8();
    v9 = *(_DWORD *)(a2 + 4);
    v10 = *(_DWORD *)(a2 + 8);
    v7[2] = *(_DWORD *)a2;
    v7[3] = v9;
    v7[4] = v10;
    v6 = v7;
    *v7 = *(_DWORD *)(a1 + 8);
    v7[1] = *(_DWORD *)(a1 + 12);
    v7[5] = v11;
  }
  return (int)v6;
}
