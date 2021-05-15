// NtSetIoCompletionEx 
 
int __fastcall NtSetIoCompletionEx(int a1, int a2, int a3, int a4, int a5)
{
  char v8; // r3
  int v9; // r5
  char v10; // r3
  int v11; // r6
  unsigned int *v12; // r4
  unsigned int v13; // r2
  int v15; // [sp+10h] [bp-20h] BYREF
  unsigned int *v16; // [sp+14h] [bp-1Ch] BYREF

  v8 = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v9 = ObReferenceObjectByHandle(a1, 2, IoCompletionObjectType, v8, (int)&v15, 0);
  if ( v9 < 0 )
    return v9;
  v10 = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v9 = ObReferenceObjectByHandle(a2, 2, dword_682574, v10, (int)&v16, 0);
  v11 = v15;
  if ( v9 >= 0 )
  {
    __dmb(0xBu);
    v12 = v16;
    do
      v13 = __ldrex(v12);
    while ( !v13 && __strex(1u, v12) );
    __dmb(0xBu);
    if ( v13 )
    {
      v9 = -1073741584;
      goto LABEL_10;
    }
    v9 = IoSetIoCompletionEx(v11, a3, a4, a5);
    if ( v9 < 0 )
    {
      __dmb(0xBu);
      *v12 = 0;
LABEL_10:
      if ( v12 )
        ObfDereferenceObject((int)v12);
      goto LABEL_12;
    }
  }
LABEL_12:
  if ( v11 )
    ObfDereferenceObject(v11);
  return v9;
}
