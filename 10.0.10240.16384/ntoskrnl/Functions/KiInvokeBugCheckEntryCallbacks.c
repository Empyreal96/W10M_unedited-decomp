// KiInvokeBugCheckEntryCallbacks 
 
__int64 __fastcall KiInvokeBugCheckEntryCallbacks(__int64 a1, int a2, int a3)
{
  int v3; // r5
  __int64 v5; // [sp+0h] [bp-20h] BYREF
  int *v6; // [sp+8h] [bp-18h]
  int v7; // [sp+Ch] [bp-14h]

  v5 = a1;
  v7 = a3;
  v6 = &KeBugCheckReasonCallbackListHead;
  v3 = KeBugCheckReasonCallbackListHead;
  if ( KeBugCheckReasonCallbackListHead && dword_624D2C )
  {
    LODWORD(v5) = &KeBugCheckReasonCallbackListHead;
    while ( 1 )
    {
      HIDWORD(v5) = v3;
      if ( (int *)v3 == &KeBugCheckReasonCallbackListHead )
        break;
      if ( KeValidateBugCheckCallbackRecord(v3, 1, &v5) )
      {
        (*(void (__fastcall **)(int, int, _DWORD, _DWORD))(v3 + 8))(1, v3, 0, 0);
        *(_BYTE *)(v3 + 24) = 3;
      }
      else if ( !(_DWORD)v5 )
      {
        return v5;
      }
      v3 = *(_DWORD *)v3;
    }
  }
  return v5;
}
