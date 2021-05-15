// CmpRecoverEnlistment 
 
int __fastcall CmpRecoverEnlistment(int a1, int a2, int a3)
{
  int v5; // r4
  int v7; // [sp+14h] [bp-3Ch] BYREF
  __int16 v8; // [sp+18h] [bp-38h] BYREF
  int v9; // [sp+1Ah] [bp-36h]
  __int16 v10; // [sp+1Eh] [bp-32h]
  __int16 v11; // [sp+20h] [bp-30h] BYREF
  int v12; // [sp+22h] [bp-2Eh]
  __int16 v13; // [sp+26h] [bp-2Ah]
  int v14; // [sp+28h] [bp-28h]
  int v15; // [sp+2Ch] [bp-24h]
  int v16; // [sp+30h] [bp-20h]
  int v17; // [sp+34h] [bp-1Ch]
  int v18; // [sp+38h] [bp-18h]
  int v19; // [sp+3Ch] [bp-14h]

  v8 = 0;
  v9 = 0;
  v10 = 0;
  v11 = 0;
  v12 = 0;
  v13 = 0;
  v5 = RtlStringFromGUIDEx(a3, (int)&v8, 1);
  if ( v5 >= 0 )
  {
    v5 = CmpSearchAddTrans(0, a1, 0, 0, a3 + 16, 1, &v7);
    if ( v5 >= 0 )
    {
      v14 = 24;
      v15 = 0;
      v17 = 576;
      v16 = 0;
      v18 = 0;
      v19 = 0;
      v5 = ZwOpenEnlistment();
      if ( v5 >= 0 )
      {
        v5 = ZwRecoverEnlistment();
        ZwClose();
      }
    }
    RtlFreeAnsiString(&v11);
    RtlFreeAnsiString(&v8);
  }
  return v5;
}
