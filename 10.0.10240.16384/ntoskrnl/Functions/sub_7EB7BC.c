// sub_7EB7BC 
 
void __fastcall sub_7EB7BC(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
  int v11; // r6
  int v12; // r8
  __int64 v13; // r1

  memset((_BYTE *)a11, 0, 60);
  *(_BYTE *)(a11 + 50) = 4;
  *(_DWORD *)(a11 + 24) = v11;
  EtwpReferenceGuidEntry(v12);
  HIDWORD(v13) = &EtwpReplyListHead;
  *(_DWORD *)(a11 + 16) = v12;
  LODWORD(v13) = EtwpReplyListHead;
  *(_QWORD *)a11 = v13;
  if ( *(int **)(v13 + 4) != &EtwpReplyListHead )
    __fastfail(3u);
  JUMPOUT(0x765876);
}
