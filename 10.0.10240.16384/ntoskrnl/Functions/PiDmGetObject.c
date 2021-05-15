// PiDmGetObject 
 
int __fastcall PiDmGetObject(int a1, int a2, int *a3)
{
  int v5; // r7
  int v6; // r8
  unsigned int v7; // r4
  int v8; // r0
  unsigned int *v9; // r2
  unsigned int v10; // r1
  int v11; // r0
  unsigned int v12; // r1
  __int16 v13; // r3
  int result; // r0

  v5 = 0;
  v6 = PiDmGetObjectManagerForObjectType();
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v7 + 308);
  ExAcquireResourceSharedLite(v6, 1);
  v8 = PiDmLookupObject(v6, a2);
  *a3 = v8;
  if ( v8 )
  {
    __dmb(0xBu);
    v9 = (unsigned int *)(v8 + 4);
    do
      v10 = __ldrex(v9);
    while ( __strex(v10 + 1, v9) );
    __dmb(0xBu);
  }
  else
  {
    v5 = -1073741772;
  }
  v11 = ExReleaseResourceLite(v6);
  v12 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v13 = *(_WORD *)(v12 + 0x134) + 1;
  *(_WORD *)(v12 + 308) = v13;
  if ( v13 || *(_DWORD *)(v12 + 100) == v12 + 100 )
    result = v5;
  else
    result = sub_7C6770(v11);
  return result;
}
