// sub_7F71B8 
 
void __fastcall sub_7F71B8(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18, int a19, int a20, int a21, int a22, char a23)
{
  int v23; // r4
  char v24; // r7
  unsigned int *v25; // r0
  unsigned int v26; // r5
  unsigned int v27; // r4

  if ( (v24 & 1) != 0 )
  {
    KiStackAttachProcess(v23, 0, (int)&a23);
    NtClose();
    KiUnstackDetachProcess((unsigned int)&a23, 0);
  }
  v25 = (unsigned int *)(v23 + 172);
  __pld((void *)(v23 + 172));
  v26 = *(_DWORD *)(v23 + 172) & 0xFFFFFFFE;
  __dmb(0xBu);
  do
    v27 = __ldrex(v25);
  while ( v27 == v26 && __strex(v26 - 2, v25) );
  if ( v27 != v26 )
    ExfReleaseRundownProtection((unsigned __int8 *)v25);
  ObfDereferenceObjectWithTag(a9);
  JUMPOUT(0x71BB34);
}
