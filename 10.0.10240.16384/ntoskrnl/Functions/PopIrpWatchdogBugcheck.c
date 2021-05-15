// PopIrpWatchdogBugcheck 
 
void __fastcall __noreturn PopIrpWatchdogBugcheck(int a1)
{
  int v1; // r5
  int v2; // r3
  int v3; // r3
  int v4; // r2
  __int64 v5; // kr00_8
  __int16 v6[2]; // [sp+8h] [bp-18h] BYREF
  void *v7; // [sp+Ch] [bp-14h]
  void *v8; // [sp+10h] [bp-10h]
  int v9; // [sp+14h] [bp-Ch]

  v1 = a1;
  if ( !*(_DWORD *)(a1 + 116) )
  {
    v2 = *(_DWORD *)(a1 + 12);
    if ( v2 )
      v3 = *(_DWORD *)(*(_DWORD *)(v2 + 176) + 20);
    else
      v3 = 0;
    v4 = *(_DWORD *)(v3 + 144);
    if ( v4 )
    {
      if ( *(unsigned __int8 *)(*(_DWORD *)(v4 + 40 * *(char *)(v4 + 34) + 108) + 112) == *(unsigned __int8 *)(a1 + 112) )
        v1 = *(_DWORD *)(v4 + 40 * *(char *)(v4 + 34) + 108);
    }
  }
  v5 = *(_QWORD *)(v1 + 8);
  PopInternalAddToDumpFile(0, 0, SHIDWORD(v5));
  IoAddTriageDumpDataBlock(v5, *(unsigned __int16 *)(v5 + 2));
  IoAddTriageDumpDataBlock(v1, 152);
  v6[0] = 0x8000;
  v6[1] = 1;
  v7 = &PopIrpList;
  v8 = &PopIrpThreadList;
  v9 = ExWorkerQueue;
  KeBugCheckEx(159, 3, *(_DWORD *)(v1 + 12), (int)v6, v5);
}
