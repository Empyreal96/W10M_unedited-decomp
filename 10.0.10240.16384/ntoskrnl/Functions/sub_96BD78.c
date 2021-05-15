// sub_96BD78 
 
void __fastcall sub_96BD78(int a1, int a2, int a3)
{
  int v3; // r5
  unsigned int v4; // r7
  _DWORD *v5; // r9
  int *v6; // r10
  _BYTE *v7; // r0
  _DWORD *v8; // r6
  int v9; // r8
  unsigned int v10; // r2

  v7 = (_BYTE *)ExAllocatePoolWithTag(1, 4 * (*v6 + v3), a3);
  v8 = v7;
  *v5 = v7;
  if ( v7 )
  {
    v9 = *v6;
    memset(v7, 0, 4 * (*v6 + v3));
    if ( v9 )
    {
      v10 = v4 - (_DWORD)v8;
      do
      {
        --v9;
        *v8 = *(_DWORD *)((char *)v8 + v10);
        ++v8;
      }
      while ( v9 );
    }
    ExFreePoolWithTag(v4);
    JUMPOUT(0x958284);
  }
  JUMPOUT(0x9582EA);
}
