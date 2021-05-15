// MiDereferenceSegmentThread 
 
int __fastcall MiDereferenceSegmentThread(__int16 *a1)
{
  int v2; // r4
  unsigned int v3; // r6
  int result; // r0
  int v5; // r4
  int v6; // r0
  int v7; // r0
  unsigned int v8[8]; // [sp+10h] [bp-100h] BYREF
  int v9[56]; // [sp+30h] [bp-E0h] BYREF

  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  KeSetPriorityThread(v2, 19);
  *(_DWORD *)(v2 + 964) |= 2u;
  v8[0] = (unsigned int)(a1 + 60);
  v8[1] = (unsigned int)(a1 + 372);
  v8[2] = (unsigned int)(a1 + 390);
  v8[3] = (unsigned int)(a1 + 380);
  v8[4] = (unsigned int)(a1 + 408);
  v8[5] = (unsigned int)(a1 + 448);
  v8[6] = (unsigned int)algn_6337A4;
  v8[7] = (unsigned int)&byte_6342AC;
  if ( a1 == MiSystemPartition )
    v3 = 8;
  else
    v3 = 6;
  while ( 2 )
  {
    result = KeWaitForMultipleObjects(v3, v8, 1, 18, 0, 0, 0, v9);
    v5 = result;
    if ( result != 1 )
      result = MiDeleteEmptySubsections((int)a1);
    switch ( v5 )
    {
      case 0:
        return result;
      case 1:
        KeResetEvent((int)(a1 + 372));
        MiDeleteEmptySubsections((int)a1);
        continue;
      case 2:
        MiProcessDereferenceList(a1);
        continue;
      case 3:
        KeResetEvent((int)(a1 + 380));
        MiRemoveUnusedSegments(a1);
        continue;
      case 4:
        MiProcessDeleteOnClose(a1);
        continue;
      case 5:
        MiDeleteControlAreaList(a1);
        continue;
      case 6:
        v6 = KeResetEvent((int)algn_6337A4);
        MiFreeClonePool(v6);
        continue;
      case 7:
        v7 = KeResetEvent((int)&byte_6342AC);
        result = sub_551E0C(v7);
        break;
      default:
        continue;
    }
    break;
  }
  return result;
}
