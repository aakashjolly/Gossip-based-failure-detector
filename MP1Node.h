/**********************************
 * FILE NAME: MP1Node.cpp
 *
 * DESCRIPTION: Membership protocol run by this Node.
 * 				Header file of MP1Node class.
 **********************************/

#ifndef _MP1NODE_H_
#define _MP1NODE_H_

#include "stdincludes.h"
#include "Log.h"
#include "Params.h"
#include "Member.h"
#include "EmulNet.h"
#include "Queue.h"
#include<memory>
/**
 * Macros
 */

static const int TREMOVE = 20;
static const int TFAIL = 5;
/*
 * Note: You can change/add any functions in MP1Node.{h,cpp}
 */


/**
 * CLASS NAME: MP1Node
 *
 * DESCRIPTION: Class implementing Membership protocol functionalities for failure detection
 */
class MP1Node {
private:
    /**
     * Message Types
     */
    enum class MsgTypes{
        JOINREQ,
        JOINREP,
        GOSSIP,
        DUMMYLASTMSGTYPE
    };

    /**
     * STRUCT NAME: MessageHdr
     *
     * DESCRIPTION: Header and content of a message
     */
    struct MessageHdr {
    	enum MsgTypes msgType;
        Address addr;
        int numElements;
    };

    EmulNet *emulNet;
    Log *log;
    Params *par;
    Member *memberNode;
    char NULLADDR[6];
    void logAdd_(int id, short port);
    void logRemove_(int id, short port);
    Address genAddress_(int id, short port);
    void addMembers_(char* data);
    vector<MemberListEntry>::iterator findMember_(int id, short port);
    void sendMemberListToNode_(Address *addr, MsgTypes msgtype,
            std::vector<MemberListEntry>& memberVector);
public:
    MP1Node(Member *, Params *, EmulNet *, Log *, Address *);
    Member * getMemberNode() {
	    return memberNode;
    }
    int recvLoop();
    static int enqueueWrapper(void *env, char *buff, int size);
    void nodeStart(char *servaddrstr, short serverport);
    int initThisNode(Address *joinaddr);
    int introduceSelfToGroup(Address *joinAddress);
    int finishUpThisNode();
    void nodeLoop();
    void checkMessages();
    bool recvCallBack(char *data, int size);
    void nodeLoopOps();
    int isNullAddress(Address *addr);
    Address getJoinAddress();
    void initMemberListTable(Member *memberNode);
    void printAddress(Address *addr);
    virtual ~MP1Node();
};

#endif /* _MP1NODE_H_ */
