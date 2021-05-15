// CmpInitCmPrivateAlloc 
 
void CmpInitCmPrivateAlloc()
{
  if ( !CmpAllocInited )
  {
    CmpFreeKCBListHead = (int)&CmpFreeKCBListHead;
    dword_6323E4 = (int)&CmpFreeKCBListHead;
    CmpAllocBucketLock = 1;
    dword_632404 = 0;
    unk_632408 = 0;
    byte_63240C = 1;
    byte_63240D = 0;
    byte_63240E = 4;
    dword_632410 = 0;
    dword_632418 = (int)&dword_632414;
    dword_632414 = (int)&dword_632414;
    CmpAllocInited = 1;
  }
}
