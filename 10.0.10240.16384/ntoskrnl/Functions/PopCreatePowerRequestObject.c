// PopCreatePowerRequestObject 
 
int __fastcall PopCreatePowerRequestObject(_DWORD *a1, _DWORD *a2)
{
  BOOL v4; // r4
  unsigned int v5; // r6
  unsigned int v6; // r6
  _DWORD *v7; // r5
  int v8; // r2
  int v9; // r8
  _DWORD *v10; // r4
  _BYTE *v12; // [sp+18h] [bp-38h] BYREF
  int v13[12]; // [sp+20h] [bp-30h] BYREF

  v4 = *a2 != 0;
  v12 = 0;
  __dmb(0xBu);
  do
  {
    v5 = __ldrex((unsigned int *)&PopPowerRequestId);
    v6 = v5 + 1;
  }
  while ( __strex(v6, (unsigned int *)&PopPowerRequestId) );
  __dmb(0xBu);
  v7 = (_DWORD *)PopPowerRequestInsertElementNoLock(v6);
  if ( !v7 )
    return -1073741670;
  v13[0] = 24;
  v13[1] = 0;
  v8 = a2[3];
  v13[3] = 32;
  v13[2] = 0;
  v13[4] = 0;
  v13[5] = 0;
  v9 = ObCreateObject(0, PopPowerRequestObjectType, v13, v4, 0, 76, v8 + 16, 0, &v12);
  if ( v9 >= 0 )
  {
    v10 = v12;
    memset(v12, 0, 76);
    v10[2] = PsGetCurrentProcessSessionId();
    v10[15] = a2;
    v10[5] = v6;
    *v7 = v10;
    v7[1] = v6;
    v7 = 0;
    *a1 = v10;
  }
  if ( v7 )
    return sub_7F334C();
  return v9;
}
