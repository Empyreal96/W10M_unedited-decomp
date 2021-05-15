// sub_96921C 
 
int sub_96921C()
{
  int v0; // r0
  int v2; // r4
  int v3; // r5
  int *v4; // r6
  int v5; // r0
  _BYTE v6[160]; // [sp-A0h] [bp-A0h] BYREF

  v5 = ExAllocatePoolWithTag(1, v3 + 1, 538996553);
  *v4 = v5;
  if ( v5 )
    memmove(v5, *(_DWORD *)(v2 + 104), v3 + 1);
  RtlInitAnsiString((unsigned int)v6, *(_DWORD *)(v2 + 108));
  v0 = IopCreateArcNamesDisk();
  if ( v0 >= 0 )
    v0 = IopCreateArcNamesCd(v2);
  return (*(int (__fastcall **)(int))&v6[156])(v0);
}
