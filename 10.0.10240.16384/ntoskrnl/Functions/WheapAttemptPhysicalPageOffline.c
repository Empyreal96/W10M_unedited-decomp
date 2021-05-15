// WheapAttemptPhysicalPageOffline 
 
int __fastcall WheapAttemptPhysicalPageOffline(int a1, char a2, int a3)
{
  char v4; // r6
  int v7; // r5
  int v8; // r0
  int v9; // r4
  int v10; // r0
  unsigned __int64 v12; // [sp+8h] [bp-30h] BYREF
  __int64 v13; // [sp+10h] [bp-28h] BYREF
  int v14; // [sp+18h] [bp-20h]
  BOOL v15; // [sp+1Ch] [bp-1Ch]

  v13 = 4096i64;
  v4 = 0;
  v12 = (unsigned __int64)(unsigned int)a1 << 12;
  if ( a3 )
  {
    v7 = 2;
  }
  else
  {
    LODWORD(v12) = (a1 << 12) | 1;
    v7 = 1;
  }
  v8 = MmMarkPhysicalMemoryAsBad((__int64 *)&v12, &v13);
  v9 = v8;
  if ( v8 >= 0 )
  {
    LODWORD(v13) = 1;
    HIDWORD(v13) = v7;
    v15 = v8 == 0;
    v14 = 1;
    WheapSqmAddToStream(7212, 2, &v13);
  }
  if ( WheapPolicyMemPersistOffline )
  {
    v10 = WheaPersistOfflinedPage(a1);
    if ( v10 >= 0 )
    {
      v4 = 1;
    }
    else
    {
      v4 = 0;
      v9 = v10;
    }
  }
  WheapLogPageOfflineAttemptEvent(a1 << 12, 0, v9 == 259, a3, v4, a2);
  return v9;
}
