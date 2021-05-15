// IopQueryDockRemovalInterface 
 
int __fastcall IopQueryDockRemovalInterface(int a1, _DWORD *a2)
{
  _BYTE *v4; // r0
  _WORD *v5; // r4
  int v6; // r5
  int v8[10]; // [sp+8h] [bp-58h] BYREF
  _DWORD v9[12]; // [sp+30h] [bp-30h] BYREF

  v9[0] = -1449824267;
  v9[1] = 299045850;
  v9[2] = -1610556521;
  v9[3] = 777142473;
  v4 = (_BYTE *)ExAllocatePoolWithTag(1, 24, 538996816);
  v5 = v4;
  if ( !v4 )
    return -1073741670;
  memset(v4, 0, 24);
  *v5 = 24;
  memset(v8, 0, sizeof(v8));
  LOWORD(v8[0]) = 2075;
  v8[2] = (int)v9;
  v5[1] = 0;
  v8[3] = 24;
  v8[4] = (int)v5;
  v8[5] = 0;
  v6 = IopSynchronousCall(a1, (int)v8, -1073741637, 0, 0);
  if ( v6 < 0 )
    ExFreePoolWithTag((unsigned int)v5);
  else
    *a2 = v5;
  return v6;
}
