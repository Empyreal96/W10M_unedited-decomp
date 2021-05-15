// sub_517330 
 
void __fastcall sub_517330(int a1, int a2, int a3)
{
  int v3; // r8
  int v4; // r9
  int v5; // r10
  int v6; // lr
  int *v7; // r10
  int v8; // t1
  __int64 v9; // r4
  unsigned int v10; // [sp+0h] [bp+0h]

  v10 = 0;
  if ( a3 )
  {
    v7 = (int *)(v5 + 72);
    do
    {
      v8 = *v7++;
      v9 = *(_QWORD *)(v8 + 128);
      v3 += *(_DWORD *)(v8 + 4872) + *(_DWORD *)(v8 + 5120) + *(_DWORD *)(v8 + 136) + *(_DWORD *)(v8 + 384);
      v4 += *(_DWORD *)(v8 + 4864) + v9;
      ++v10;
      v6 += *(_DWORD *)(v8 + 4868) + HIDWORD(v9);
    }
    while ( v10 < ExpNumberOfNonPagedPools );
  }
  JUMPOUT(0x437588);
}
