// sub_50A658 
 
void __fastcall sub_50A658(_DWORD *a1)
{
  int v1; // r4
  unsigned int v2; // r5

  v2 = *(unsigned __int16 *)(v1 + 4);
  if ( v2 < 0x200 )
  {
    RtlpInterlockedPushEntrySList((unsigned __int64 *)v1, a1);
    if ( v2 < 0x40 )
LABEL_5:
      JUMPOUT(0x4DAB0A);
  }
  else
  {
    ++*(_DWORD *)(v1 + 36);
    ExFreePoolWithTag(a1, 0);
  }
  KeSetEvent(v1 + 8, 1, 0);
  goto LABEL_5;
}
