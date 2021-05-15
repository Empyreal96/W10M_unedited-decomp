// FsRtlNotifyCompleteIrpList 
 
int __fastcall FsRtlNotifyCompleteIrpList(int a1)
{
  *(_WORD *)(a1 + 36) &= 0xFFFDu;
  *(_DWORD *)(a1 + 60) = 0;
  *(_DWORD *)(a1 + 64) = 0;
  return sub_7E5838();
}
