// PspQueryQuotaLimits 
 
int __fastcall PspQueryQuotaLimits(int a1, int a2, int a3, unsigned int a4, unsigned int *a5, char a6)
{
  int v9; // r4
  _DWORD *v10; // r2
  int v11; // r3
  int v12; // r3
  int v14; // [sp+10h] [bp-88h] BYREF
  int v15; // [sp+14h] [bp-84h] BYREF
  int v16; // [sp+18h] [bp-80h] BYREF
  int v17; // [sp+1Ch] [bp-7Ch] BYREF
  int v18; // [sp+20h] [bp-78h] BYREF
  int v19; // [sp+28h] [bp-70h] BYREF
  _DWORD v20[13]; // [sp+2Ch] [bp-6Ch] BYREF
  _BYTE v21[56]; // [sp+60h] [bp-38h] BYREF

  v19 = 0;
  memset(v20, 0, sizeof(v20));
  if ( a4 != 32 && a4 != 56 )
    return -1073741820;
  v9 = ObReferenceObjectByHandleWithTag(a1, 4096, PsProcessType, a6, 2035381072, &v14, 0);
  if ( v9 >= 0 )
  {
    v10 = *(_DWORD **)(v14 + 332);
    __dmb(0xBu);
    v19 = v10[96];
    v20[0] = v10[32];
    v20[3] = v10[160];
    v20[7] = v10[224];
    v20[5] = -1;
    v20[6] = -1;
    KiStackAttachProcess(v14, 0, (int)v21);
    v9 = MmQueryWorkingSetInformation(&v16, &v17, &v18, &v20[1], &v20[2], &v15);
    KiUnstackDetachProcess((unsigned int)v21, 0);
    if ( (v15 & 4) != 0 )
      v11 = 1;
    else
      v11 = 2;
    if ( (v15 & 1) != 0 )
      v12 = v11 | 4;
    else
      v12 = v11 | 8;
    v20[11] = v12;
    ObfDereferenceObjectWithTag(v14);
    if ( v9 >= 0 )
    {
      memmove(a3, (int)&v19, a4);
      if ( a5 )
        *a5 = a4;
    }
  }
  return v9;
}
