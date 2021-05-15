// ObDrainDeferredObjectDeletion 
 
int __fastcall ObDrainDeferredObjectDeletion(int a1, int a2, int a3, int a4)
{
  int result; // r0
  int i; // [sp+8h] [bp-8h] BYREF

  for ( i = a4;
        ;
        result = ExBlockOnAddressPushLock(
                   (int)&ObpRemoveObjectWait,
                   (unsigned __int64 *)&ObpRemoveObjectList,
                   (unsigned int *)&i,
                   4,
                   0) )
  {
    i = ObpRemoveObjectList;
    if ( !ObpRemoveObjectList )
      break;
  }
  return result;
}
