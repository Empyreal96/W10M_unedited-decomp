// EtwpAddDataSource 
 
int __fastcall EtwpAddDataSource(int a1)
{
  int v1; // r4
  _DWORD *v3; // r0

  v1 = *(_DWORD *)(a1 + 348);
  if ( v1 && (v1 & 1) == 0 )
    return v1;
  v3 = (_DWORD *)ExAllocatePoolWithTag(512, 16, 1400337477);
  if ( !v3 )
    return 0;
  *v3 = 0;
  v3[1] = 0;
  v3[2] = 0;
  v3[3] = 0;
  if ( v1 )
    JUMPOUT(0x8085FE);
  return sub_8085FC();
}
