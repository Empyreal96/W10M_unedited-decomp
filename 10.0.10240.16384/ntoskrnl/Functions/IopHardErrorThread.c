// IopHardErrorThread 
 
__int64 __fastcall IopHardErrorThread(int a1, int a2, int a3, int a4)
{
  int v4; // r0
  unsigned int v5; // r4
  int v6; // r5
  unsigned int v7; // r0
  __int64 v9; // [sp+0h] [bp-20h]
  int v10; // [sp+Ch] [bp-14h] BYREF

  HIDWORD(v9) = a2;
  v10 = a4;
  do
  {
    KeWaitForSingleObject((unsigned int)algn_631A3C, 0, 0, 0, 0);
    v4 = IopRemoveHardErrorPacket();
    v5 = v4;
    if ( ExReadyForErrors )
    {
      HIDWORD(v9) = &v10;
      LODWORD(v9) = 7;
      ExRaiseHardError(*(_DWORD *)(v4 + 8), *(_DWORD *)(v4 + 16) != 0);
    }
    v6 = IopCheckHardErrorEmpty();
    v7 = *(_DWORD *)(v5 + 16);
    if ( v7 )
      ExFreePoolWithTag(v7);
    ExFreePoolWithTag(v5);
  }
  while ( v6 );
  return v9;
}
