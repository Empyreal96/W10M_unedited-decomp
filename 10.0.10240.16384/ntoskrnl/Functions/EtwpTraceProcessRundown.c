// EtwpTraceProcessRundown 
 
int __fastcall EtwpTraceProcessRundown(int a1, int a2, int *a3, int a4)
{
  int v6; // r2
  int v8; // r3
  unsigned __int16 v10[2]; // [sp+20h] [bp-278h] BYREF
  int v11; // [sp+24h] [bp-274h]
  int *v12; // [sp+28h] [bp-270h] BYREF
  int v13; // [sp+2Ch] [bp-26Ch] BYREF
  unsigned __int16 v14[4]; // [sp+30h] [bp-268h] BYREF
  int v15; // [sp+38h] [bp-260h] BYREF
  char v16[32]; // [sp+40h] [bp-258h] BYREF
  int v17[100]; // [sp+60h] [bp-238h] BYREF
  int v18[42]; // [sp+1F0h] [bp-A8h] BYREF

  v6 = *(unsigned __int8 *)(a4 + 37);
  v11 = *(_DWORD *)(a4 + 8);
  v10[1] = *(_WORD *)(a4 + 12);
  v10[0] = 0;
  EtwpBuildProcessEvent(a1, a3, v6, (int)v16, &v15, v18, &v13, v17, v14, v10, &v12);
  if ( a3 == (int *)807 )
    v8 = 5249029;
  else
    v8 = 5249028;
  EtwpLogKernelEvent(v18, a2, v13, (int)a3, v8);
  if ( v11 != *(_DWORD *)(a4 + 8) )
    return sub_7D00A0();
  RtlFreeAnsiString(v14);
  if ( v12 )
    ExFreePoolWithTag((unsigned int)v12);
  return 0;
}
