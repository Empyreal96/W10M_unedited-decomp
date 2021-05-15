// CmpGetValueForAudit 
 
int __fastcall CmpGetValueForAudit(int a1, int a2, _DWORD *a3, int a4)
{
  int v4; // r5
  int (__fastcall *v7)(int, int, int *); // r4
  int v10; // r0
  int v11; // r9
  int v12; // r0
  int v13; // r7
  unsigned int v14; // r4
  int v15; // r0
  char v17[4]; // [sp+10h] [bp-30h] BYREF
  int v18; // [sp+14h] [bp-2Ch] BYREF
  int v19; // [sp+18h] [bp-28h] BYREF
  int v20; // [sp+1Ch] [bp-24h] BYREF
  unsigned int v21[8]; // [sp+20h] [bp-20h] BYREF

  v4 = 0;
  v7 = *(int (__fastcall **)(int, int, int *))(a1 + 4);
  v19 = -1;
  v20 = -1;
  v18 = 0;
  v17[0] = 0;
  v10 = v7(a1, a2, &v20);
  v11 = v10;
  if ( !v10 )
    return -1073741670;
  v12 = CmpGetValueData(a1, a2, v10, v21, &v18, v17, (int)&v19);
  v13 = v18;
  if ( !v12 )
    goto LABEL_7;
  v14 = v21[0];
  if ( v21[0] )
  {
    v15 = ExAllocatePoolWithTag(1, v21[0], a4);
    a3[2] = v15;
    if ( v15 )
    {
      memmove(v15, v13, v14);
      a3[1] = v14;
      *a3 = *(_DWORD *)(v11 + 12);
      goto LABEL_8;
    }
LABEL_7:
    v4 = -1073741670;
  }
LABEL_8:
  if ( v13 )
  {
    if ( v17[0] == 1 )
      ExFreePoolWithTag(v13);
    else
      (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v19);
  }
  (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v20);
  return v4;
}
