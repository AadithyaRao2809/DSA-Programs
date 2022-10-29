#include "queue.h"
#include "dll.h"
#include "music_player.h"
#include <stdio.h>
#include <stdlib.h>

playlist_t* create_playlist() // return a newly created doubly linked list
{
	// DO NOT MODIFY!!!
	playlist_t* playlist = (playlist_t*) malloc(sizeof(playlist_t));
	playlist->list = create_list();
	playlist->num_songs = 0;
	playlist->last_song = NULL;
	return playlist;
}

void delete_playlist(playlist_t* playlist) // delete the playlist
{
	// DO NOT MODIFY!!!
	delete_list(playlist->list);
	free(playlist);
}

music_queue_t* create_music_queue() // return a newly created queue
{
	// DO NOT MODIFY!!!
	return create_queue();
}

void clear_music_queue(music_queue_t* q) // clear the queue q
{	
	// DO NOT MODIFY!!!
	delete_queue(q);
}

void add_song(playlist_t* playlist, int song_id, int where) // TODO: add a song id to the end of the playlist
{
	if(where == -1)
		insert_front(playlist,song_id);
	if(where == -2)
		insert_back(playlist,song_id);
	else
		insert_after(playlist,song_id,where);
}

void delete_song(playlist_t* playlist, int song_id) // TODO: remove song id from the playlist
{
	delete_node(playlist->list,song_id);
	playlist->num_songs = playlist->list->size;

	if(playlist->last_song->data == song_id)
	{
		if(playlist->last_song->next == NULL)
			playlist->last_song = playlist->list->head;
		playlist->last_song = playlist->last_song->next;
	}
}

song_t* search_song(playlist_t* playlist, int song_id) // TODO: return a pointer to the node_t where the song id is present in the playlist
{
	song_t* temp = playlist->list->head;
	
	while(temp!=NULL)
	{
		if(temp->data == song_id)
			return temp;
		temp = temp->next;
	}
	return temp;
}

void search_and_play(playlist_t* playlist, int song_id) // TODO: play the song with given song_id from the list(no need to bother about the queue. Call to this function should always play the given song and further calls to play_next and play_previous)
{
	song_t* temp = playlist->list->head;

	while(temp != NULL)
	{
		if(temp->data == song_id)
			break;
		temp = temp->next;
	}
	if(temp!=NULL)
		playlist->last_song = temp;
	
	play_song(playlist->last_song->data);
}

void play_next(playlist_t* playlist, music_queue_t* q) // TODO: play the next song in the linked list if the queue is empty. If the queue if not empty, play from the queue
{
	if(q->size != 0)
	{
		play_song(dequeue(q));
		return;
	}
	
	if(playlist->last_song->next == NULL)
	{
		playlist->last_song = playlist->list->head;
		play_song(playlist->last_song->data);
		return;
	}

	playlist->last_song = playlist->last_song->next;
	play_song(playlist->last_song->data);
}

void play_previous(playlist_t* playlist) // TODO: play the previous song from the linked list
{
	if(playlist->last_song->prev!=NULL)
	{
		playlist->last_song = playlist->last_song->prev;
		return;
	}
	playlist->last_song = playlist->list->head;
	play_song(playlist->last_song->data);
}

void play_from_queue(music_queue_t* q) // TODO: play a song from the queue
{
	play_song(dequeue(q));
	
}

void insert_to_queue(music_queue_t* q, int song_id) // TODO: insert a song id to the queue
{
	enqueue(q,song_id);
}

void swap(node_t* a, node_t* b, list_t* playlist)
{
	if(a==b)
		return;
	if(a->next == b)
	{
		a->next = b->next;
		b->prev = a->next;

		if(a->next != NULL)
			a->next->prev = a;
		
		if(b->prev != NULL)
			b->prev->next = b;

		b->next = a;
		a->prev = b;
	}
	else
	{
		node_t* p = b->prev;
		node_t* n = b->next;

		b->prev = a->prev;
        b->next = a->next;

        a->prev = p;
        a->next = n;

        if (b->next != NULL)
            b->next->prev = b;
        if (b->prev != NULL)
            b->prev->next = b;

        if (a->next != NULL)
            a->next->prev = a;
        if (a->prev != NULL)
            a->prev->next = a; 

		if(a->prev == NULL)
			playlist->head = a;
		if(a->next == NULL)
			playlist->tail = a;

		if(b->prev == NULL)
			playlist->head = b;
		if(b->next == NULL)
			playlist->tail = b;
	}
}

void reverse(playlist_t* playlist) // TODO: reverse the order of the songs in the given playlist. (Swap the node_ts, not data)
{
	song_t* left = playlist->list->head; 
	song_t* right = playlist->list->tail; 

	while(left!=right && left->prev!=right)
		swap(left,right,playlist);
		left = left->next;
		right = right->prev;
	
}



void k_swap(playlist_t* playlist, int k) // TODO: swap the node_t at position i with node_t at position i+k upto the point where i+k is less than the size of the linked list
{
	song_t* front = playlist->list->head;
	song_t* back = playlist->list->head;
	for(int i=0; i<k; i++)
		front = front->next;

	while(front!=NULL)
	{
		swap(back,front,playlist);
		back = back->next;
		front = front->next;
	}
}


void shuffle(playlist_t* playlist, int k) // TODO: perform k_swap and reverse
{
	k_swap(playlist,k);
	reverse(playlist);
}

song_t* debug(playlist_t* playlist) // TODO: if the given linked list has a cycle, return the start of the cycle, else return null. Check cycles only in forward direction i.e with the next pointer. No need to check for cycles in the backward pointer.
{
	song_t* slow = playlist->list->head;
	song_t* fast = playlist->list->head;

	while(fast->next!=NULL && fast==NULL && fast!=slow)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	if(fast->next == NULL || fast == NULL)
		return fast;
	fast = fast->next;
	int k=1;
	while(fast!=slow)
	{
		fast = fast->next;
		k++;
	}

	slow = playlist->list->head;
	fast = playlist->list->head;
	for(int i=0; i<k; i++)
		fast = fast->next;
	
	while(fast!=slow)
	{
		fast = fast->next;
		slow = slow->next;
	}
	return fast;
}

void display_playlist(playlist_t* p) // Displays the playlist
{
	// DO NOT MODIFY!!!
	display_list(p->list);
}

void play_song(int song_id)
{
	// DO NOT MODIFY!!!
	printf("Playing: %d\n", song_id);
}

