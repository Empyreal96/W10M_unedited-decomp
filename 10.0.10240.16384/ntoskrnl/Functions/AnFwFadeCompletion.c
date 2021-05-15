// AnFwFadeCompletion 
 
void AnFwFadeCompletion()
{
  int v0; // r0
  __int64 v1; // [sp+8h] [bp-10h] BYREF

  if ( (dword_619018 & 0xC00) != 3072 )
  {
    LogFwStat(&v1, 0, 7i64);
    BgpFwReleaseLock();
    v0 = KeWaitForSingleObject((unsigned int)&unk_649DC8, 0, 0, 0, 0);
    BgpFwAcquireLock(v0);
    if ( off_618094 )
    {
      sub_8DF528();
    }
    else
    {
      if ( dword_6180B4 )
      {
        BgpGxRectangleDestroy(dword_6180B4);
        dword_6180B4 = 0;
      }
      if ( off_6180B8 )
      {
        BgpGxRectangleDestroy(off_6180B8);
        off_6180B8 = 0;
      }
      if ( dword_6180BC )
      {
        BgpGxRectangleDestroy(dword_6180BC);
        dword_6180BC = 0;
      }
      if ( off_6180DC )
      {
        BgpGxRectangleDestroy(off_6180DC);
        off_6180DC = 0;
      }
      if ( dword_6180E0 )
      {
        BgpGxRectangleDestroy(dword_6180E0);
        dword_6180E0 = 0;
      }
    }
  }
}
