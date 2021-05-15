// IopPostProcessIrp 
 
int __fastcall IopPostProcessIrp(int a1)
{
  unsigned int v1; // r9
  int result; // r0
  int v3; // [sp+8h] [bp-40h] BYREF
  char v4[60]; // [sp+Ch] [bp-3Ch] BYREF

  v3 = 0;
  v1 = *(_DWORD *)(a1 + 48) & 0xFFFFFFFC;
  *(_DWORD *)(a1 + 52) = 0;
  if ( v1 == *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) )
    result = IopCompleteRequest(a1 + 64, v4, &v3, a1 + 100, &v3);
  else
    result = sub_523318();
  return result;
}
